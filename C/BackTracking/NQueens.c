#include <stdio.h>
#define N 8
int count;
int place(int k,int i,int *x)
{
    int j;
    for(j=0;j<k;j++) //checkattack  as old queen is placed at jth position
    {
          //old queen is placed at jth row of x[j] column
          //new queen to be placed at kth row of ith column
        if(i==x[j] || abs(k-j)==abs(i-x[j]))
            return 0;
    }
    return 1;
}
 
void Nqueen(int k)
{
    int i,j;
    static int x[N];  //solution vector contains column number of queen
    for(i=0;i<N;i++)  //determines appropriate column number of the kth queen to be placed
    {
        if(place(k,i,x))
        {
            x[k]=i;
            if(k==N-1)
            {
                count++;
                for(j=0;j<=k;j++)
                    printf("%d  ",x[j]);
                printf("\n");
            }
            else
                Nqueen(k+1);
        }
    }
 
}
 
int main()
{
    Nqueen(0);
    printf("Total %d solutions are possible\n",count);
    return 0;
}
