/* LC ID :  #84
 * Type  :  Stack
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
    int largestRectangleArea(vector<int>& height) {
        if (height.empty()) return 0;
        stack<int> s;
        int left = 0, h, best = 0;

        //init
        for (int i = 0; i < height.size(); i++)
            best = max(best, height[i]);

        //left to right
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                h = height[s.top()];
                s.pop();
                left = s.empty()?0:s.top()+1;
                if (h*(i-left) > best)
                    best = h*(i-left);
            }
            s.push(i);
        }

        //left in stack, non-decreasing height
        while (!s.empty()) {
            h = height[s.top()];
            s.pop();
            left = s.empty()?0:s.top()+1;
            if (h*(height.size()-left) > best)
                best = h*(height.size()-left);
        }

        return best;
    }
};

int main() {
    Solution sol;
    int n; cin >> n; int x; vector<int> h;
    for (int i = 0; i < n; i++) { cin >> x; h.push_back(x); }
    cout << sol.largestRectangleArea(h) << endl;

    return 0;
}
