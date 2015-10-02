/* LC ID :  #96
 * Type  :  Dynamic Programming
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
    int numTrees(int n) {
        int f[n+1][n+2]; //len l, starts at i
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n+1; i++) f[0][i] = f[1][i] = 1;

        for (int l = 2; l <= n; l++)
            for (int i = 1; i+l-1 <= n; i++) {
                for (int j = i; j <= i+l-1; j++) //mid
                    f[l][i] += f[j-i][i] * f[l-(j-i+1)][j+1];
            }

        return f[n][1];
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.numTrees(n);
    cout << ans << endl;

    return 0;
}
