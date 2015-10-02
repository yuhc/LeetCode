/* LC ID :  #169
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
    int majorityElement(vector<int>& nums) {
        int count = 0, ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!count) {
                count++;
                ans = nums[i];
            }
            else {
                if (nums[i] == ans) count++;
                else count--;
            }
        }
        return ans;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,3,2,3,1,4,1,1,3,1,4,1,1,2,1,2};
    cout << sol.majorityElement(nums) << endl;

    return 0;
}
