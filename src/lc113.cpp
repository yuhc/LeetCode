/* LC ID :  #113
 * Type  :  DFS
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> path;
        dfs(root, sum, ans, path);
    }

    void dfs(TreeNode *t, int sum, vector<vector<int>>& ans, vector<int>& path) {
        path.push_back(t->val);
        if (!t->left && !t->right && sum == t->val) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        if (t->left) dfs(t->left, sum-t->val, ans, path);
        if (t->right) dfs(t->right, sum-t->val, ans, path);
        path.pop_back();
    }
};

int main() {
    Solution sol;
    

    return 0;
}
