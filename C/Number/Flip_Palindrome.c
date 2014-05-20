int flip_digit(int d)
{
  switch (d = val%10) {
    /* flippable numbers */
    case 0:
    case 1:
    case 5:
    case 8:
      return d;
    /* unflippable numbers */
    case 2:
    case 3:
    case 4:
    case 7:
       return -1;
    case 6:
       return 9;
    case 9:
       return 6;
    default:
       return -1;
  }
}
int flip (int val, int carry)
{
  int d;
  if (val == 0) return carry;
  d = flip_digit(val%10);
  if (d < 0) return d;
  return flip(val/10, carry*10+d);
}

int isFlipped(int val)
{
  return (val == flip(val, 0)); 
}