/* LC ID :  #47
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/08/2015
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
    void dfs(vector<int>& oneSol, bool bj[], vector<vector<int>>& ans, vector<int>& nums) {
        if (oneSol.size() == nums.size()) {
            ans.push_back(oneSol);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
            if (!bj[i]) {
                bj[i] = true;
                oneSol.push_back(nums[i]);
                dfs(oneSol, bj, ans, nums);
                oneSol.pop_back();
                bj[i] = false;
                while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;

        sort(nums.begin(), nums.end());
        bool bj[nums.size()];
        memset(bj, 0, sizeof(bj));
        vector<int> oneSol;
        dfs(oneSol, bj, ans, nums);
    }
};

int main() {
    Solution sol;
    int n, x; vector<int> nums;
    cin >> n; for (int i = 0; i < n; i++) { cin >> x; nums.push_back(x); }
    vector<vector<int>> ans = sol.permuteUnique(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
