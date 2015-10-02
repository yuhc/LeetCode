/* LC ID :  #108
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/19/2015
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
#include <climits>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode *root = new TreeNode(nums[nums.size()/2]);
        dfs(root, 0, nums.size(), nums);
        return root;
    }

    void dfs(TreeNode *t, int left, int right, vector<int>& nums) {
        int mid = (left+right) >> 1;
        if (left < mid) {
            t->left = new TreeNode(nums[(left+mid)/2]);
            dfs(t->left, left, mid, nums);
        }
        if (mid+1 < right) {
            t->right = new TreeNode(nums[(mid+1+right)/2]);
            dfs(t->right, mid+1, right, nums);
        }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
