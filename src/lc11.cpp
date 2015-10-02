/* LC ID :  #11
 * Type  :  Order Squence
 * Author:  Hangchen Yu
 * Date  :  04/18/2015
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
    int maxArea(vector<int>& height) {
        //the volume is decided by the lower edge
        int left = 0, right = height.size()-1;
        int maxV = 0, t;
        while (left < right) {
            t = min(height[left], height[right]) * (right-left);
            maxV = max(maxV, t);
            if (height[left] > height[right]) right--;
            else left++;
        }
        return maxV;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> h;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        h.push_back(t);
    }
    cout << sol.maxArea(h) << endl;

    return 0;
}
