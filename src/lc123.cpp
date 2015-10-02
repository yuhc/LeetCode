/* LC ID :  #123
 * Type  :  Dynamic Programming
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
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
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int n = prices.size();
        int minp[n], maxp[n]; //minp: from left to right; maxp: from right to left
        minp[0] = prices[0]; maxp[n-1] = prices[n-1];
        for (int i = 1; i < n; i++)
            minp[i] = min(minp[i-1], prices[i]);
        for (int i = n-2; i >= 0; i--)
            maxp[i] = max(maxp[i+1], prices[i]);

        int left[n], right[n];
        left[0] = 0;
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1];
            if (minp[i-1] < prices[i] && left[i-1] < prices[i]-minp[i-1])
                left[i] = prices[i]-minp[i-1];
        }
        right[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            right[i] = right[i+1];
            if (maxp[i+1] > prices[i] && right[i+1] < maxp[i+1]-prices[i])
                right[i] = maxp[i+1]-prices[i];
        }

        int best = 0, t;
        for (int i = -1; i < n; i++) { //0..i, i+1..n-1
            if (i < 0) t = right[i];
            else if (i == n-1) t = left[i];
            else t = left[i] + right[i+1];
            if (t > best) best = t;
        }

        return best;
    }
};

int main() {
    Solution sol;
    vector<int> s = {1, 2, -1, 2, 5, 7, 0};
    cout << sol.maxProfit(s) << endl;

    return 0;
}
