/* LC ID :  #110
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool flag = true;
        depth(root, flag);
        return flag;
    }

    int depth(TreeNode *t, bool &flag) {
        if (!t) return 0;
        int ld = depth(t->left, flag);
        int rd = depth(t->right, flag);
        if (!(ld==rd || ld==rd+1 || ld+1==rd)) flag = false;
        return max(ld, rd)+1;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
