/*
From a given integer array values, find if a Total value is possible or not? The numbers in the array can be used more than once. 
example 
int[] points = {3, 7}; 
isScorePossible(points, 10) => true 
isScorePossible(points, 9) => true
*/

dp[0] = 1;
 for (int i=0; i < N; i++)
    for(j = a[i]; j <= W; j++)
           dp[j] |= dp[j-a[i]];
 return dp[W];