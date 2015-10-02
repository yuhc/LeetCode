/* LC ID :  #94
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/16/2015
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
    void travel(TreeNode* t, vector<int>& ans) {
        if (!t) return;
        travel(t->left, ans);
        ans.push_back(t->val);
        travel(t->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        travel(root, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
