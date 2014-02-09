pow(x,y) = x ^ y

int pow(int x, int y, int *flag) {

    int i=0, res = 1;
    
    flag = 0;
    
    if(y>=0) {
        for (i=0; i<y ; i++){
            // if (sign(res,x)) res < MAXPOSINT / x  potential overflow
            // else res > MAXNEGINT / x  
            // abs(res) < (res*x) MAXINT / abs(x)
            if (overflow(res,x)) {
               //overlow = (overflow << 1) & 1; 
               flag = flag | (1<<1);
               break;
            }
            res * = x;
            //check if res overflows 
            // overlow = (overflow << 1) & 1
        }
    }
    else {
        if (x == 0)
            flag = flag | 1;
        else {
            for (i=0 ; i>y; i--)
                res / = x;
        }
    }
    return res;
}

if (res > MAX_INT) {
  // overflow
}

if overflow (int res, int x) {
    if (abs(res) / abs(x) > MAX_INT / abs(x))
       return 1;
    return 0;
}

abs(result) {
    int normalized_value = res > 0 ? res : -res
    return normalized_value;
}
y >= 0, y=0
y =-1


-2, 4, -8, 16, -32, ... 
