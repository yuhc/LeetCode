/* LC ID :  #115
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
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (!n || !m) return 0;

        int f[n+1][m+1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                f[i][j] = f[i-1][j] + f[i-1][j-1]*(s[i-1]==t[j-1]);
        }

        return f[n][m];
    }
};

int main() {
    Solution sol;
    

    return 0;
}
