/* LC ID :  #104
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/18/2015
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxd = 0;
        dfs(root, 1, maxd);
        return maxd;
    }

    void dfs(TreeNode *t, int k, int& maxd) {
        if (k > maxd) maxd = k;
        if (t->left) dfs(t->left, k+1, maxd);
        if (t->right) dfs(t->right, k+1, maxd);
    }
};

int main() {
    Solution sol;
    

    return 0;
}
