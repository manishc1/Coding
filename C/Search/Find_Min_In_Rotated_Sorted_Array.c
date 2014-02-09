// array of ints, [min_int, max_int]
// unique, sorted, but rotated

// [-11, -5, 2, 7, 13]
// [2, 7, 13, -11, -5]
// [13, -11, -5, 2, 7]

// findMin

int findMin(int* arr, int n) {
    int m;
    int l = 0, u = n-1;
    while(l <= u) {
        if (a[l] < a[u])
            return a[l];
        m = (l+u) / 2;
        if ((m+1 < n) && a[m] > a[m+1]) {
            return a[m+1];
        }
        else if (m-1 >= 0 && a[m-1] > a[m]) {
            return a[m];
        }
        else if(a[l] > a[m]) {
            u = m;
        } else {
            l = m;
        }
    }
}
