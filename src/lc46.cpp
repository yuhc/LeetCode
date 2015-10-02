/* LC ID :  #46
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/07/2015
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
    void generate(vector<int>& current, bool bj[], vector<vector<int>>& ans, vector<int>& nums) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
            if (!bj[i]) {
                bj[i] = true;
                current.push_back(nums[i]);
                generate(current, bj, ans, nums);
                current.pop_back();
                bj[i] = false;
            }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;

        vector<int> current;
        bool bj[nums.size()];
        memset(bj, false, sizeof(bj));
        generate(current, bj, ans, nums);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
