/* LC ID :  #87
 * Type  :  Division & Conqur
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
        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,s1.length()-i), s2.substr(i,s2.length()-i))) return true;
            if (isScramble(s1.substr(0,i), s2.substr(s2.length()-i,i)) && isScramble(s1.substr(s1.length()-i,i), s2.substr(0,i))) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;
    cin >> s1 >> s2;
    cout << sol.isScramble(s1, s2) << endl;

    return 0;
}
