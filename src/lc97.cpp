/* LC ID :  #97
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
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length()+s2.length() != s3.length()) return false;

        bool f[s2.length()+1]; //f[i][j], i is omitted
        memset(f, false, sizeof(f));
        for (int i = 0; i <= s1.length(); i++) {
            if (!i) f[0] = true;
            else f[0] = f[0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= s2.length(); j++) {
                f[j] = (f[j-1] && s2[j-1] == s3[i+j-1]) || (f[j] && s1[i-1] == s3[i+j-1]);
            }
        }

        return f[s2.length()];
    }
};

int main() {
    Solution sol;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << sol.isInterleave(s1, s2, s3) << endl;

    return 0;
}
