/* LC ID :  #35
 * Type  :  Binary Search
 * Author:  Hangchen Yu
 * Date  :  09/01/2015
 */
#include <iostream>
#include <cstdio>

using namespace std;

//copy the Solution class here
int searchInsert(int* nums, int numsSize, int target) {
    if (!numsSize) return 0;

    int left = 0, right = numsSize - 1;
    int mid = (left + right) >> 1;
    while (left <= right) {
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
        mid = (left + right) >> 1;
    }

    return ((mid < 0 || nums[mid] < target)? mid+1:left);
}

int main() {
    int nums[10], t;
    cin >> t;
    for (int i = 0; i < 4; i++) cin >> nums[i];
    cout << searchInsert(nums, 4, t) << endl;
    return 0;
}
