/*
Print the numbers of form 2^i.5^j in increasing order. For eg: 
1, 2, 4, 5, 8, 10, 16, 20
*/

import java.util.*;

class G216
{
 public static void main(String[] args) {printIncreasing(50);}

 public static void printIncreasing(int length)
 {
  long[] values = new long[length];
  values[0] = 1;
  int index2 = 0;
  int index5 = 0;

  for (int i = 0; i < length; i++)
  {
   System.out.println(values[i] + "");

   if (i < (length - 1))
   {
    if (values[index2] * 2 == values[index5] * 5)
    {
     values[i + 1] = values[index2] * 2;
     index2++;
     index5++;
    }
    else if (values[index2] * 2 < values[index5] * 5)
    {
     values[i + 1] = values[index2] * 2;
     index2++;
    }
    else
    {
     values[i + 1] = values[index5] * 5;
     index5++;
    }
   }
  }
 }
}
