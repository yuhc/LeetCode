/* LC ID :  #140
 * Type  :  String + DFS
 * Author:  Hangchen Yu
 * Date  :  09/14/2015
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
#include <unordered_set>
#include <utility>
#include <cmath>

using namespace std;

//copy the Solution class here
class Solution {
public:
    void dfs(int k, string& s, vector<string>& tmp, vector<string>& ans, unordered_set<string>& wordDict, bool canBreak[]) {
        if (k == s.length()) {
            string t = tmp[0];
            for (int i = 1; i < tmp.size(); i++)
                t += " " + tmp[i];
            ans.push_back(t);
            return;
        }
        for (int i = k; i < s.length(); i++) {
            if (!canBreak[i+1]) continue;
            string subs = s.substr(k,i-k+1);
            if (wordDict.count(subs)) {
                tmp.push_back(s.substr(k,i-k+1));
                dfs(i+1, s, tmp, ans, wordDict, canBreak);
                tmp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        bool canBreak[n]; //right-side
        memset(canBreak, false, sizeof(canBreak));
        canBreak[n] = true;
        for (int i = n-1; i >= 0; i--)
            for (int j = 1; j <= n-i; j++)
                if (canBreak[i+j] && wordDict.count(s.substr(i,j))) {
                    canBreak[i] = true;
                    break;
                }

        vector<string> tmp;
        vector<string> ans;
        dfs(0, s, tmp, ans, wordDict, canBreak);
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    //s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //unordered_set<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    s = "abcd";
    unordered_set<string> wordDict = {"a","abc","b","cd"};
    vector<string> ans = sol.wordBreak(s, wordDict);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
