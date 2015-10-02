/* LC ID :  #105
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        if (preorder.empty()) return root;
        root = new TreeNode(preorder[0]);
        build(root, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }

    void build(TreeNode* father, vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight) return;
        for (int i = inLeft; i <= inRight; i++)
            if (inorder[i] == preorder[preLeft]) {
                if (i != inLeft) {
                    father->left = new TreeNode(preorder[preLeft+1]);
                    build(father->left, preorder, preLeft+1, preLeft+i-inLeft, inorder, inLeft, i-1);
                }
                if (i != inRight) {
                    father->right = new TreeNode(preorder[preLeft+i-inLeft+1]);
                    build(father->right, preorder, preLeft+i-inLeft+1, preRight, inorder, i+1, inRight);
                }
            }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
