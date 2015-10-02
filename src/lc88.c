/* LC ID :  #88
 * Type  :  Array
 * Author:  Hangchen Yu
 * Date  :  09/15/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
void merge(int* nums1, int m, int* nums2, int n) {
    int i = m-1;
    for (; i >= 0; i--) nums1[i+n] = nums1[i]; //shift right
    int j = 0, k = 0; i = n;
    while (j < n && i < n+m) {
        if (nums1[i] <= nums2[j]) nums1[k++] = nums1[i++];
        else nums1[k++] = nums2[j++];
    }
    if (i == n+m)
        while (j < n) nums1[k++] = nums2[j++];
}
int main() {

    return 0;
}
