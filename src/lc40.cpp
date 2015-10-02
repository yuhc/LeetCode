/* LC ID :  #40
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/05/2015
 * Flags :  std=c++11
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
    void dfs(int k, vector<int>& current, vector<vector<int>> &ans, vector<int>& candidates, int target) {
        if (!target) {
            ans.push_back(current);
            return;
        }

        for (int i = k; i < candidates.size(); i++) {
            if (target < candidates[i]) break;
            if (i == k || candidates[i] != candidates[i-1]) {
                current.push_back(candidates[i]);
                dfs(i+1, current, ans, candidates, target-candidates[i]);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        dfs(0, current, ans, candidates, target);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates;
    int n, target, t;
    cin >> n >> target;
    for (int i = 0; i < n; i++) { cin >> t; candidates.push_back(t); }
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
