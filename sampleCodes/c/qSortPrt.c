#include "stdio.h"
#include "math.h"
void qSortPrt(int *a, int n) {
	int sizeOFThisA = n;
	// Return if the length of n > 2
	if (sizeOFThisA<=1  )
		return;

	// Test Code examine the quality of N
	
	printf("\n InputN -- %d --- \n", sizeOFThisA);


	// Right, Left and Pivote Pointers
    int p = a[(sizeOFThisA -1) / 2];
    int *l = a;
    int *r = a + sizeOFThisA - 1;

	// Transversion mechanisim
    while (l <= r) {
		printf("n=%d, L = %d, R = %d, P = %d, \n", sizeOFThisA, *l, *r, p);
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
	sizeOFThisA = sizeOFThisA / 2;
	// -----  Debug: 
	for (int i = 0; i < sizeOFThisA; i++) { printf("[%d]", a[i]); }
	int nleft = r - a + 1;
	int nRight = a + sizeOFThisA - l;
	printf("\n--nleft--%d--", nleft);
	printf("nRight--%d--", nRight);
	printf("\n");

	int *myleft = a;
	int myRight = a + sizeOFThisA - l;
	printf("--nleft--%d--",*a);
	printf("nRight--%d--", myRight);
	printf("\n");
	//--------------------------------------------------/

	qSortPrt(a, sizeOFThisA);
	qSortPrt( a + myRight, sizeOFThisA);
}

int main () {
    int a[] = {35,33,42,10,14,19,27,44,26,31 };
    int n = sizeof a / sizeof a[0];
	
	qSortPrt(a, n);
    return 0;
}


//  [1]: https://www.cse.ust.hk/~dekai/271/notes/L01a/quickSort.pdf
//  [2]: http://www.cprogramming.com/tutorial/computersciencetheory/quicksort.html
 // [3]: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort

/*

0x000000990d8ffba8 = 657357536168

0x000000990d8ffbb8 = 657357536184


------------------------------------------------------------------
35|33|42|10|14|19|27|44|26|31   n=10 | L = 35 | R = 31 | P = 42 |
------------------------------------------------------------------
------------------------------------------------------------------
35|33|42|10|14|  				 n=5 | L = 33 | R = 14  | P = 42 |
------------------------------------------------------------------
------------------------------------------------------------------
35|33|42|10|14| 				 n=5 | L = 42 | R = 14  | P = 42 |
------------------------------------------------------------------
------------------------------------------------------------------
35|33|42|10|14|  				 n=5 | L = 10 | R = 14  | P = 42 |
------------------------------------------------------------------
[35][33][14][10][42]			 n=5 | L = 42 | R = 10  | P = 42 |
------------------------------------------------------------------
n=10, L = 35, R = 31, P = 14,
n=10, L = 35, R = 26, P = 14,
n=10, L = 35, R = 44, P = 14,
n=10, L = 35, R = 27, P = 14,
n=10, L = 35, R = 19, P = 14,
n=10, L = 35, R = 14, P = 14,
n=10, L = 33, R = 10, P = 14,
n=10, L = 42, R = 42, P = 14,
[14][10][42][33][35][19][27][44][26][31]

InputN -- 5 ---
n=10, L = 35, R = 31, P = 14,
n=10, L = 35, R = 26, P = 14,
n=10, L = 35, R = 44, P = 14,
n=10, L = 35, R = 27, P = 14,
n=10, L = 35, R = 19, P = 14,
n=10, L = 35, R = 14, P = 14,
n=10, L = 33, R = 10, P = 14,
n=10, L = 42, R = 42, P = 14,
[14][10][42][33][35][19][27][44][26][31]
--nleft--2--nRight--8--
--nleft--14--nRight--8--

InputN -- 2 ---
n=5, L = 14, R = 35, P = 42,
n=5, L = 10, R = 35, P = 42,
n=5, L = 42, R = 35, P = 42,
n=5, L = 33, R = 33, P = 42,
[14][10][35][33][42]
--nleft--4--nRight--1--
--nleft--14--nRight--1--

InputN -- 1 ---
n=2, L = 14, R = 10, P = 14,
[10][14]
--nleft--1--nRight--1--
--nleft--10--nRight--1--

InputN -- 1 ---
n=2, L = 14, R = 35, P = 14,
n=2, L = 14, R = 14, P = 14,
[14][35]
--nleft--0--nRight--1--
--nleft--14--nRight--1--

InputN -- 2 ---
n=5, L = 26, R = -858993460, P = -858993460,
n=5, L = 31, R = -858993460, P = -858993460,
n=5, L = -858993460, R = -858993460, P = -858993460,
[-858993460][-858993460][-858993460][31][26]
--nleft--2--nRight--2--
--nleft---858993460--nRight--2--

InputN -- 1 ---
n=2, L = -858993460, R = -858993460, P = -858993460,
[-858993460][-858993460]
--nleft--1--nRight--1--
--nleft---858993460--nRight--1--

InputN -- 1 ---
n=2, L = -858993460, R = 31, P = -858993460,
n=2, L = -858993460, R = -858993460, P = -858993460,
[-858993460][31]
--nleft--0--nRight--1--
--nleft---858993460--nRight--1--


*/
