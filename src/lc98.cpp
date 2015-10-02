/* LC ID :  #98
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
    bool traverse(TreeNode* t, int &last, bool &first) {
        if (!t) return true;
        if (t->left && !traverse(t->left, last, first)) return false ;
        if (t->val <= last && !first) return false;
        last = t->val;
        first = false;
        if (t->right && !traverse(t->right, last, first)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int last = INT_MIN;
        bool first = true;
        return traverse(root, last, first);
    }
};

int main() {
    Solution sol;
    

    return 0;
}
