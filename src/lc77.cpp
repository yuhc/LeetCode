/* LC ID :  #77
 * Type  :  DFS
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
    void dfs(int i, int n, int k, vector<vector<int>>& ans, vector<int>& tmp) {
        if (!k) {
            ans.push_back(tmp);
            return;
        }
        for (int j = i; j <= n-k+1; j++) {
            tmp.push_back(j);
            dfs(j+1, n, k-1, ans, tmp);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k > n) return ans;
        vector<int> tmp;
        dfs(1, n, k, ans, tmp);
        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans = sol.combine(n, k);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
