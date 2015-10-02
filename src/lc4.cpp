/* LC ID :  #4
 * Type  :  Binary Search
 * Author:  Hangchen Yu
 * Date  :  04/15/2015
 */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <cmath>

using std::swap;
using std::vector;
using std::pair;

//copy the Solution class here
/**
 * Let k = (m+n)/2. Suppose m > k/2, n > k/2.
 * Compare a[k/2-1] and b[k/2-1]:
 *     a[k/2-1] < b[k/2-1]: search the (k-k/2)-th in a[k/2] and b
 *     a[k/2-1] > b[k/2-1]: similar
 *     a[k/2-1] = b[k/2-1]: they are the median
 */
class Solution {
public:
    double findKthNumber(int A[], int m, int B[], int n, int k) {
        // assume that the length of B is greater than A
        if (m > n)
            return findKthNumber(B, n, A, m, k);
        // when A is empty
        if (m == 0)
            return B[k-1];
        // when k meets the boundary
        if (k == 1)
            return fmin(A[0], B[0]);

        // divide k by two
        int i = fmin(k/2, m);
        int j = k - i;
        if (A[i-1] < B[j-1])
            return findKthNumber(A+i, m-i, B, n, k-i);
        else if (A[i-1] > B[j-1])
            return findKthNumber(A, m, B+j, n-j, k-j);
        else
            return A[i-1];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int tot = m + n;
        if (tot&1)
            return findKthNumber(A, m, B, n, (tot+1)/2);
        else
            return findKthNumber(A, m, B, n, tot/2)/2
                 + findKthNumber(A, m, B, n, tot/2+1)/2;
    }
};

int main() {
    Solution s;
    int A[100] = { 1, 2, 3, 4, 5 };
    int B[100] = { 2, 3, 4, 5, 6, 7 };
    printf("%lf\n", s.findMedianSortedArrays(A, 5, B, 6));
    return 0;
}
