/* LC ID :  #120
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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (!n) return 0;
        int f[2][n];

        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++)
                f[i&1][j] = INT_MAX;
            for (int j = 0; j <= i; j++)
                if (!j) f[i&1][j] = f[(i-1)&1][j] + triangle[i][j];
                else if (j == i) f[i&1][j] = f[(i-1)&1][j-1] + triangle[i][j];
                else f[i&1][j] = min(f[(i-1)&1][j-1], f[(i-1)&1][j]) + triangle[i][j];
        }

        int best = INT_MAX;
        for (int i = 0; i < n; i++)
            best = min(best, f[(n-1)&1][i]);
        return best;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
