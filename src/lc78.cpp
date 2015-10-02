/* LC ID :  #78
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
    void dfs(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp) {
        if (i >= nums.size()) {
            ans.push_back(tmp);
            return;
        }
        dfs(i+1, nums, ans, tmp);
        tmp.push_back(nums[i]);
        dfs(i+1, nums, ans, tmp);
        tmp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (nums.empty()) {
            ans.push_back(tmp); //emptyset
            return ans;
        }
        sort(nums.begin(), nums.end());
        dfs(0, nums, ans, tmp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,4,2,5};
    vector<vector<int>> ans = sol.subsets(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << ans.size() << endl;

    return 0;
}
