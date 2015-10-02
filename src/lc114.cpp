/* LC ID :  #114
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

//copy the Solution class here
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left) flatten(root->right);
        else {
            if (!root->right) {
                root->right = root->left;
                root->left = NULL;
            }
            else {
                TreeNode *t = root->left;
                while (t->right) t = t->right;
                t->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            flatten(root->right);
        }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
