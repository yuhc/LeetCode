/* LC ID :  #80
 * Type  :  Array
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int count = 2;
        int i = 2, tmp;
        while (i < nums.size()) {
            while (nums[count-1] == nums[count-2] && nums[count-1] == nums[i])
                i++;
            if (i < nums.size()) swap(nums[count++], nums[i++]);
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,2,3,4,4,5,5,5};
    cout << sol.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
