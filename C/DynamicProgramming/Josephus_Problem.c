 def josephus_rec(n, k):
   if n ==1:
     return 1
   else:
     return ((josephus_rec(n-1,k)+k-1) % n)+1

 //Alternatively a simple loop can also be run like:
 def josephus_nonrec(n, k):
   r = 0
   i = 2
   while i <= n:
     r = (r + k) % i;
     i+= 1
   return r+1

/*
A dynamic programming solution in Haskell:
 josephus n k = josephus' [1..n] k where
     josephus' xs k
         | length xs == 1 = head xs
         | otherwise      = josephus' (killnext k xs) k where
         killnext k xs = take (length xs - 1) (drop k (cycle xs))
*/

//A somewhat more elaborate version in Java:
 int josephus(int n, int k) {
       return josephus(n, k, 1);
 }
 int josephus(int n, int k, int startingPoint) {
     if(n == 1)
         return 1;
     int newSp = (startingPoint + k - 2) % n + 1;
 
     int survivor = josephus(n - 1, k, newSp);
     if (survivor < newSp) {
         return survivor;
     } else
         return survivor + 1;
 }
