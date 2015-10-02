/* LC ID :  #257
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/13/2015
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
    string num2str(int n) {
        if (!n) return "0";
        bool neg = (n<0);
        if (neg) n = -n;
        string s = "";
        while (n > 0) {
            s = char(n%10+'0') + s;
            n /= 10;
        }
        if (neg) s = '-' + s;
        return s;
    }

    void dfs(TreeNode* t, vector<string>& ans, vector<int>& num) {
        num.push_back(t->val);
        if (!t->left && !t->right) {
            string s = num2str(num[0]);
            for (int i = 1; i < num.size(); i++)
                s += "->" + num2str(num[i]);
            ans.push_back(s);
            num.pop_back();
            return;
        }

        if (t->left) dfs(t->left, ans, num);
        if (t->right) dfs(t->right, ans, num);
        num.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        vector<int> num;
        dfs(root, ans, num);
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
