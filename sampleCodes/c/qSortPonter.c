void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
	int nleft = r - a + 1;
	int nRight = a + n - l;
    quick_sort(a, nleft);
    quick_sort(l, nRight);
}

int main () {
    int a[] = {35,33,42,10,14,19,27,44,26,31};
    int n = sizeof a / sizeof a[0];
    quick_sort(a, n);
    return 0;
}


//  [1]: https://www.cse.ust.hk/~dekai/271/notes/L01a/quickSort.pdf
//  [2]: http://www.cprogramming.com/tutorial/computersciencetheory/quicksort.html
 // [3]: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
