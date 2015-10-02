/* LC ID :  #122
 * Type  :  Greedy
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
//if   a < b < c < d
//then d-a > (d-c)+(b-a)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int best = 0, k = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i-1]) {
                best += prices[i-1] - prices[k];
                k = i;
            }
        }
        best += prices[prices.size()-1] - prices[k];
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> s = {1, 2, -1, 0, 5, 3, 0};
    cout << sol.maxProfit(s) << endl;

    return 0;
}
