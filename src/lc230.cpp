/* LC ID :  #230
 * Type  :  Tree
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
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

//copy the Solution class here
class Solution {
public:
    bool travel(TreeNode* t, int k, int &n, int &ans) {
        if (!t) return false;

        if (travel(t->left, k, n, ans)) return true;
        n++;
        if (n == k) {
            ans = t->val;
            return true;
        }
        if (travel(t->right, k, n, ans)) return true;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans, n = 0;
        travel(root, k, n, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
