/* LC ID :  #111
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int mind = INT_MAX;
        dfs(root, 1, mind);
        return mind;
    }

    void dfs(TreeNode *t, int k, int& mind) {
        if (!t->left && !t->right && k < mind) mind = k;
        if (t->left) dfs(t->left, k+1, mind);
        if (t->right) dfs(t->right, k+1, mind);
    }
};

int main() {
    Solution sol;
    

    return 0;
}
