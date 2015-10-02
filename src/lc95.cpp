/* LC ID :  #95
 * Type  :  Dynamic Programming
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
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;
        for (int i = 1; i <= n; i++)
            dp[{i,i}] = {new TreeNode(i)};
        return generate(1, n, dp);
    }

    vector<TreeNode*> generate(int left, int right, map<pair<int, int>, vector<TreeNode*>>& dp) {
        vector<TreeNode*> ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }

        auto it = dp.find({left, right});
        if (it != dp.end()) return it->second;

        for (int i = left; i <= right; i++) {
            vector<TreeNode*> left_t = generate(left, i-1, dp);
            vector<TreeNode*> right_t = generate(i+1, right, dp);
            for (int j = 0; j < left_t.size(); j++)
                for (int k = 0; k < right_t.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_t[j];
                    root->right = right_t[k];
                    ans.push_back(root);
                }
        }
        dp[{left, right}] = ans;

        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
