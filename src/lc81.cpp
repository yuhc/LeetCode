/* LC ID :  #81
 * Type  :  Binary Search
 * Author:  Hangchen Yu
 * Date  :  09/16/2015
 */
#include <iostream>
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

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int left = 0, right = nums.size()-1;
        int mid;

        while (left <= right) {
            mid = (left+right) >> 1;
            if (nums[mid] == target) return true;

            if (nums[mid] < nums[right]) {  //right is ordered
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (nums[mid] > nums[right]) {  //left is ordered
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                right--;
        }

        return false;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
