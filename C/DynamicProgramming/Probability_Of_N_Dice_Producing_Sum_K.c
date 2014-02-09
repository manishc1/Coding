/*
You are given n dices each with heads numbered from 1 to m. You are to throw the n dices and note down the sum of the numbers on each of the n dices. You'll be give a number x and its a win if the sum obtained is greater than x. The problem is the find out the winning probability given n, m and x. 

Note 1<=n<=100, 
1<=m<=10, 
m<=x<=n*m.
*/

/*Google loves such probability computations based on dynamic programming 

If P(n, x) is the probability that n die generate a sum greater than or equal to x, then P(n, x) follows this recursive definition:

P(n, x) = (1/m) * sum { P(n-1, x-i), 1<=i<=m }
P(1, x) = { 0 if x > m, (m-x+1) / m, otherwise }

The RHS term computes the probability of generating a sum >= x-i using n-1 die and the probability of the nth dice generating a value k so that the total sum becomes >=x 
*/
