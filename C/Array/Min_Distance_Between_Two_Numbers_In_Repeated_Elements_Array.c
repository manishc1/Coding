/*
Consider there is an array with duplicates and u r given two numbers as input and u have to return the minimum distance between the two in the array with minimum complexity.
*/

pos1 = pos2 = dis = INT_MAX;
for(int i = 0; i < n; i++)
{
   if (a[i] == num1) pos1 = i ;
   if (a[i] == num2) pos2 = i ;
   if (pos1 < INT_MAX && pos2 < INT_MAX)
       dis = min (dis, abs(pos1-pos2) );   
}
