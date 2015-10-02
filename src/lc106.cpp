/* LC ID :  #106
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = NULL;
        if (postorder.empty()) return root;
        root = new TreeNode(postorder.back());
        build(root, inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }

    void build(TreeNode* father, vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight)  {
        if (postLeft > postRight) return;
        for (int i = inLeft; i <= inRight; i++)
            if (inorder[i] == postorder[postRight]) {
                if (i != inLeft) {
                    father->left = new TreeNode(postorder[postLeft+i-1-inLeft]);
                    build(father->left, inorder, inLeft, i-1, postorder, postLeft, postLeft+i-1-inLeft);
                }
                if (i != inRight) {
                    father->right = new TreeNode(postorder[postRight-1]);
                    build(father->right, inorder, i+1, inRight, postorder, postLeft+i-inLeft, postRight-1);
                }
            }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
