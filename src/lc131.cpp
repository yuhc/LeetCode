/* LC ID :  #131
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
#include <set>
#include <utility>
#include <cmath>

using namespace std;

//copy the Solution class here
class Solution {
public:
    void dfs(int k, string& s, vector<string>& tmp, vector<vector<string>>& ans, bool** isPalin) {
        if (k == s.length()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = k; i < s.length(); i++)
            if (isPalin[k][i]) {
                tmp.push_back(s.substr(k,i-k+1));
                dfs(i+1, s, tmp, ans, isPalin);
                tmp.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        bool **isPalin = (bool**)malloc(n*sizeof(bool*));
        for (int i = 0; i < n; i++)
            isPalin[i] = (bool*)malloc(n*sizeof(bool));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) isPalin[i][j] = false;

        //char as center
        for (int i = 0; i < n; i++) isPalin[i][i] = true;
        for (int i = 1; i < n-1; i++)
            for (int l = 1; l <= min(i,n-i-1); l++)
                if (s[i-l] == s[i+l]) isPalin[i-l][i+l] = true;
                else break;
        //slot as center
        for (int i = 0; i < n-1; i++)
            for (int l = 1; l <= min(i+1,n-i-1); l++)
                if (s[i-l+1] == s[i+l]) isPalin[i-l+1][i+l] = true;
                else break;

        vector<string> tmp;
        vector<vector<string>> ans;
        dfs(0, s, tmp, ans, isPalin);
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    vector<vector<string>> ans = sol.partition(s);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
