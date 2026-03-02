extern int FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
  struct { int val; int saved; char buf[8]; } frame;

  frame.saved = param_1;
  FUN_0603f3f6(param_1, frame.buf, 4);
  FUN_0603f3f6(frame.saved, &frame.val, 4);
  return frame.val;
}
