/* LC ID :  #124
 * Type  :  Tree Dynamic Programming
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

//copy the Solution class here
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        dfs(root, best);
        return best;
    }

    int dfs(TreeNode *t, int &best) {
        if (!t) return 0;
        int t1 = dfs(t->left, best);
        int t2 = dfs(t->right, best);
        t1 = max(t1, 0); t2 = max(t2, 0);
        if (t1+t2+t->val > best) best = t1+t2+t->val;
        return max(t1,t2)+t->val;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
