/* LC ID :  #129
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/22/2015
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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

    void dfs(TreeNode* t, int &sum, int k) {
        int now = k*10 + t->val;
        if (!t->left && !t->right) {
            sum += now;
            return;
        }

        if (t->left) dfs(t->left, sum, now);
        if (t->right) dfs(t->right, sum, now);
    }
};

int main() {
    Solution sol;
    

    return 0;
}
