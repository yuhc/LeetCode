/* LC ID :  #103
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
    vector<vector<int>> levelOrderButtom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<TreeNode*> current, next;
        vector<int> tmp;
        current.push_back(root);
        tmp.push_back(root->val);
        TreeNode *t;

        while (!current.empty()) {
            ans.push_back(tmp);
            next.clear();
            tmp.clear();
            for (int i = 0; i < current.size(); i++) {
                t = current[i];
                if (t->left) {
                    next.push_back(t->left);
                    tmp.push_back(t->left->val);
                }
                if (t->right) {
                    next.push_back(t->right);
                    tmp.push_back(t->right->val);
                }
            }
            current = next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
