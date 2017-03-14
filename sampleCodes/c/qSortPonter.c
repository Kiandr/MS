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
    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}

int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    quick_sort(a, n);
    return 0;
}


//  [1]: https://www.cse.ust.hk/~dekai/271/notes/L01a/quickSort.pdf
//  [2]: http://www.cprogramming.com/tutorial/computersciencetheory/quicksort.html
 // [3]: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
