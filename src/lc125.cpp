/* LC ID :  #125
 * Type  :  String
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
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = 0, right = s.length()-1;
        while (left < right) {
            while (left < right && !isAlphaNumeric(s[left])) left++;
            while (left < right && !isAlphaNumeric(s[right])) right--;
            if (left >= right) break;
            if (normal(s[left]) != normal(s[right])) return false;
            left++; right--;
        }
        return true;
    }

    char normal(char x) {
        if (x >= 'A' && x <= 'Z') return (x-'A'+'a');
        else return x;
    }

    bool isAlphaNumeric(char x) {
        return (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9');
    }
};

int main() {
    Solution sol;
    string a;
    cin >> a;
    cout << sol.isPalindrome(a) << endl;

    return 0;
}
