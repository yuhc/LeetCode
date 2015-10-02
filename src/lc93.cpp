/* LC ID :  #93
 * Type  :  Backtracing
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
    void dfs(int k, string s, vector<string>& ans, vector<string>& now) {
        if (!s.empty() && k > 3) return;
        if (s.empty() && k <= 3) return;
        if (s.empty() && k > 3) {
            string tmp = now[0];
            for (int i = 1; i < 4; i++) tmp += "." + now[i];
            ans.push_back(tmp);
            return;
        }

        int len = s.length();
        now.push_back(s.substr(0,1));
        dfs(k+1, s.substr(1,len-1), ans, now);
        now.pop_back();

        if (len > 1 && s[0] != '0') {
            now.push_back(s.substr(0,2));
            dfs(k+1, s.substr(2,len-2), ans, now);
            now.pop_back();
        }

        if (s.length() > 2) {
            int t = (s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
            if (t >= 256 || t < 100) return;
            now.push_back(s.substr(0,3));
            dfs(k+1, s.substr(3,len-3), ans, now);
            now.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans, now;
        dfs(0, s, ans, now);
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.restoreIpAddresses(s)[0] << endl;

    return 0;
}
