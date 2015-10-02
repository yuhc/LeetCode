/* LC ID :  #75
 * Type  :  Sort
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize) {
    int i = 0, j = numsSize-1, k;
    while (i < numsSize && nums[i] == 0) i++;
    while (j >= 0 && nums[j] == 2) j--;

    k = i;
    while (k <= j) {
        if (k != j && nums[k] == 2) {
            swap(nums+k, nums+j);
            j--;
        }
        else if (i != k && nums[k] == 0) {
            swap(nums+k, nums+i);
            i++;
        }
        else k++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *m = (int*) malloc(sizeof(int)*n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", m+i);
    sortColors(m, n);
    for (i = 0; i < n; i++)
        printf("%d ", m[i]);
    printf("\n");

    return 0;
}
