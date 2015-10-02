/* LC ID :  #229
 * Type  :  Moore Majority Voting
 * Author:  Hangchen Yu
 * Date  :  09/13/2015
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
//http://www.cs.utexas.edu/~moore/best-ideas/mjrty/example.html
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, ans1, count2 = 0, ans2;
        for (int i = 0; i < nums.size(); i++) {
            if ((count1 && ans1 == nums[i]) || !count1) {
                count1++;
                ans1 = nums[i];
            }
            else if ((count2 && ans2 == nums[i]) || !count2) {
                count2++;
                ans2 = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        if (ans1 == ans2) ans2++; //make different
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans1) count1++;
            if (nums[i] == ans2) count2++;
        }
        vector<int> ans;
        if (count1 > nums.size()/3) ans.push_back(ans1);
        if (count2 > nums.size()/3) ans.push_back(ans2);
        return ans;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,3,2,3,1,4,1,1,3,1,4,1,1,2,1,2};
    vector<int> ans = sol.majorityElement(nums);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    return 0;
}
