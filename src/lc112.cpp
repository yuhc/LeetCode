/* LC ID :  #112
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return dfs(root, sum);
    }

    bool dfs(TreeNode *t, int sum) {
        if (!t->left && !t->right && sum == t->val) return true;
        if (!t->left && !t->right) return false;

        if (t->left && dfs(t->left, sum-t->val)) return true;
        if (t->right && dfs(t->right, sum-t->val)) return true;
        return false;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
