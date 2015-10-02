/* LC ID :  #116
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/20/2015
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

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL),
    next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }

    void dfs(TreeLinkNode *t, TreeLinkNode *pre) {
        if (t == pre->left)
            t->next = pre->right;
        else {
            if (!pre->next)
                t->next = NULL;
            else
                t->next = pre->next->left;
        }
        if (t->left) {
            dfs(t->left, t);
            dfs(t->right, t);
        }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
