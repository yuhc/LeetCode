/* LC ID :  #99
 * Type  :  DFS/Morris Traversal
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
    TreeNode *pre = NULL, *first = NULL, *second = NULL;

    void dfs(TreeNode* t) {
        if (!t) return;

        dfs(t->left);

        if (pre && pre->val > t->val) {
            if (!first) {
                first = pre; second = t;
            }
            else
                second = t;
        }

        pre = t;
        dfs(t->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};

int main() {
    Solution sol;
    

    return 0;
}
