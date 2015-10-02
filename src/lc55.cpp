/* LC ID :  #55
 * Type  :  Greedy
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
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;

        int best = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > best) return false;
            if (i + nums[i] > best) best = i + nums[i];
            if (best >= nums.size()) return true;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> t;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        t.push_back(x);
    }
    cout << sol.canJump(t) << endl;

    return 0;
}
