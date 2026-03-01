# Feature Harvest Loop

Every new RE tool follows this cycle. No exceptions.

1. **Implement** the feature (automation.cpp, Python tool, or both)
2. **Test** with a script that exercises the feature against our Daytona build
   - The test must produce concrete, verifiable output (addresses, matches, diffs)
   - Iterate until the test passes cleanly — no discrepancies, no logical gaps
   - If a result surprises you, STOP. Investigate before moving on.
3. **Document** findings from the test run in the workstream directory
4. **Commit** only when the test is clean and makes sense. One feature per commit.

Do not batch features. Do not skip testing. Do not commit untested tools.
