/* LC ID :  #41
 * Type  :  Array 
 * Author:  Hangchen Yu
 * Date  :  09/06/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
#define swap(x, y) { int t = x; x = y; y = t; }

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    for (; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i]-1])
        {
            int j = nums[i];
            swap(nums[i], nums[j-1]);
        }
    }

    for (i = 0; i < numsSize; i++)
        if (nums[i] != i + 1) return i + 1;
    return numsSize + 1;
}

int main() {
    int nums[100], n;
    scanf("%d", &n);
    int i = 0;
    for (; i < n; i++) scanf("%d", nums+i);
    int ans = firstMissingPositive(nums, n);
    printf("%d\n", ans);
    return 0;
}
