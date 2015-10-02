/* LC ID :  #16
 * Type  :  Array, Sort
 * Author:  Hangchen Yu
 * Date  :  04/23/2015
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
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int closest = INT_MAX/2;
        for (int a = 0; a < nums.size()-2;) {
            int b = a+1, c = nums.size()-1;
            while (b < c) {
                if (abs(nums[a]+nums[b]+nums[c]-target) < abs(closest-target))
                    closest = nums[a] + nums[b] + nums[c];
                if (nums[a] + nums[b] + nums[c] < target)
                    b++;
                else if (nums[a] + nums[b] + nums[c] > target)
                    c--;
                else
                    return target;
            }
            while (nums[a] == nums[++a] && a < nums.size()-2);
        }

        return closest;
    }
};

int main() {
    Solution sol;
    vector<int> num;
    int n, ta, x;
    cin >> n >> ta;
    for (int i = 0; i < n; i++) {
        cin >> x;
        num.push_back(x);
    }
    int t;
    t = sol.threeSumClosest(num, ta);
    cout << t << endl;

    return 0;
}
