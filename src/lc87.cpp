/* LC ID :  #87
 * Type  :  Dynamic Programming
 * Author:  Hangchen Yu
 * Date  :  09/17/2015
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
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        if (s1.empty()) return true;
        int len = s1.length();

        bool f[len+1][len][len];  //length l, s1 starts at i, s2 starts at j
        memset(f, false, sizeof(f));
        for (int l = 1; l <= len; l++)
            for (int i = 0; i+l-1 < len; i++)
                for (int j = 0; j+l-1 < len; j++) {
                    if (l == 1) f[l][i][j] = s1[i] == s2[j];
                    for (int k = 1; k < l; k++) {
                        if (f[k][i][j] && f[l-k][i+k][j+k]) f[l][i][j] = true;
                        if (f[k][i][j+l-k] && f[l-k][i+k][j]) f[l][i][j] = true;
                        if (f[l][i][j]) break;
                    }
                }

        return f[len][0][0];
    }
};

int main() {
    Solution sol;
    string s1, s2;
    cin >> s1 >> s2;
    cout << sol.isScramble(s1, s2) << endl;

    return 0;
}
