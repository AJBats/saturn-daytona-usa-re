#!/bin/bash
# Categorize missing functions from aprog.s

APROG="/mnt/d/Projects/SaturnReverseTest/build/aprog.s"
MISSING="/mnt/d/Projects/SaturnReverseTest/tools/missing_list.txt"
OUTPUT="/mnt/d/Projects/SaturnReverseTest/tools/categorized.txt"

# Pre-build a line number index for all function labels
grep -n '^FUN_[0-9A-Fa-f]*:' "$APROG" | tr -d '\r' > /tmp/func_lines_idx.txt
echo "Built index: $(wc -l < /tmp/func_lines_idx.txt) labels"

# Also find all label positions for computing function sizes
grep -n '^[A-Za-z_][A-Za-z0-9_]*:' "$APROG" | tr -d '\r' > /tmp/all_labels_idx.txt

count=0
total=$(wc -l < "$MISSING" | tr -d ' \r')

while IFS= read -r func; do
    func_clean=$(echo "$func" | tr -d '\r')
    label="${func_clean}:"
    count=$((count + 1))

    if [ $((count % 50)) -eq 0 ]; then
        echo "Processing $count / $total..." >&2
    fi

    # Find this label in the line index (case-insensitive)
    line_info=$(grep -i ":${label}$" /tmp/func_lines_idx.txt | head -1)
    if [ -z "$line_info" ]; then
        echo "${func_clean}|NOT_FOUND|0|"
        continue
    fi

    line_num=$(echo "$line_info" | cut -d: -f1)

    # Find next label to determine function boundary
    next_label_line=$(awk -F: -v ln="$line_num" '$1 > ln {print $1; exit}' /tmp/all_labels_idx.txt)
    if [ -z "$next_label_line" ]; then
        end_line=$((line_num + 200))
    else
        end_line=$((next_label_line - 1))
    fi

    # Get code between this label and next
    code=$(sed -n "$((line_num+1)),${end_line}p" "$APROG" | tr -d '\r')

    # Count instructions and identify patterns
    insn_count=0
    has_rts=0
    has_jsr=0
    has_bsr=0
    has_bra=0
    data_words=0
    first_insn=""
    all_insns=""

    while IFS= read -r codeline; do
        [ -z "$codeline" ] && continue

        # Extract the instruction from the comment
        insn=$(echo "$codeline" | sed -n 's|.*\/\* [0-9A-Fa-f]*: \(.*\) \*\/.*|\1|p' | sed 's/ *$//')

        if [ -z "$insn" ]; then
            continue
        fi

        # Check for data directives masquerading as code
        case "$insn" in
            .word*|.long*|.byte*) data_words=$((data_words + 1)); continue ;;
        esac

        insn_count=$((insn_count + 1))
        if [ $insn_count -eq 1 ]; then first_insn="$insn"; fi
        all_insns="${all_insns}|${insn}"

        case "$insn" in
            rts*) has_rts=1 ;;
            jsr*) has_jsr=1 ;;
            bsr*) has_bsr=1 ;;
            bra*) has_bra=1 ;;
        esac
    done <<< "$code"

    # Categorize based on patterns
    addr=$(echo "$func_clean" | sed 's/FUN_//')

    if [ $insn_count -eq 0 ]; then
        category="DATA_LABEL"
    elif [ $insn_count -le 2 ] && [ $has_bra -eq 1 ]; then
        category="TRAMPOLINE"
    elif [ $insn_count -le 2 ] && [ $has_rts -eq 1 ]; then
        category="STUB"
    elif [ "$addr" \> "060088CB" ] && [ "$addr" \< "06009E61" ]; then
        category="GAME_STATE_HANDLER"
    elif [ $insn_count -le 6 ] && [ $has_rts -eq 1 ] && [ $has_jsr -eq 0 ] && [ $has_bsr -eq 0 ]; then
        category="TINY_LEAF"
    elif [ $has_rts -eq 1 ] && [ $has_jsr -eq 0 ] && [ $has_bsr -eq 0 ]; then
        category="LEAF_FUNCTION"
    elif [ $has_rts -eq 1 ]; then
        category="CALL_FUNCTION"
    elif [ $has_bra -eq 1 ] && [ $has_rts -eq 0 ]; then
        category="TAIL_ONLY"
    else
        category="UNKNOWN"
    fi

    echo "${func_clean}|${category}|${insn_count}|${first_insn}"
done < "$MISSING" > "$OUTPUT"

echo "Done! Results in $OUTPUT" >&2
