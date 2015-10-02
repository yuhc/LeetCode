/* LC ID :  #14
 * Type  :  Common Prefix
 * Author:  Hangchen Yu
 * Date  :  04/23/2015
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string tmp = "";
            for (int j = 0; j < strs[i].length() && j < ans.length(); j++)
                if (strs[i][j] == ans[j])
                    tmp += ans[j];
                else
                    break;
                ans = tmp;
            }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> strs;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        strs.push_back(s);
    }
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}
