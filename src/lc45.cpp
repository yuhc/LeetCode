/* LC ID :  #45
 * Type  :  Greedy
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
//f[i]: the minimum steps to reach i
//p[i]: the position where steps == i
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        int f[n], p[n];
        f[0] = -1;
        memset(p, 0, sizeof(p));
        int i, j;

        for (i = 0, j = 0; i < n; i++) {
            f[i] = f[p[j]] + 1;
            int t = (f[i]+1>=n?n-1:f[i]+1);
            if (i + nums[i] > p[t] && (t < n-1 || (t == n-1 && f[t] == 0)))
                p[t] = i + nums[i] >= n ? n : i + nums[i];
            if (i == p[j+1]) j++;
        }

        return f[n-1];
    }
};

int main() {
    Solution sol;
    int n, x; vector<int> s;
    cin >> n; for (int i = 0; i < n; i++) { cin >> x; s.push_back(x); }
    cout << sol.jump(s) << endl;

    return 0;
}
