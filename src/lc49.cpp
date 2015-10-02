/* LC ID :  #49
 * Type  :  Sort
 * Author:  Hangchen Yu
 * Date  :  09/02/2015
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.empty()) return ans;

        map<string, int> key;
        map<string, int>::iterator it;
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if ((it = key.find(s)) != key.end()) {
                int k = it->second;
                ans[k].push_back(strs[i]);
            }
            else {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                ans.push_back(tmp);
                key[s] = ans.size()-1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n; string s; vector<string> ss;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s; ss.push_back(s);
    }
    vector<vector<string>> ans = sol.groupAnagrams(ss);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << "\"" << ans[i][j] << "\", ";
        cout << endl;
    }
    return 0;
}
