/* LC ID :  #22
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  05/06/2015
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
    vector<string> ans;

    void dfs(string s, int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }

        if (right > left)
            dfs(s+')', left, right-1);
        if (left > 0)
            dfs(s+'(', left-1, right);
    }

    vector<string> generateParenthesis(int n) {
        if (!n) return ans;
        dfs("", n, n);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<string> ans;
    ans = sol.generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
