/* LC ID :  #53
 * Type  :  Simple Dynamic Programming
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
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0, best = -1000000;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > best) best = sum;
            if (sum < 0) sum = 0;
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}
