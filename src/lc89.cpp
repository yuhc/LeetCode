/* LC ID :  #8
 * Type  :  Math
 * Author:  Hangchen Yu
 * Date  :  09/16/2015
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
    vector<int> grayCode(int n) {
        vector<int> ans;
        int t;
        for (int i = 0; i < (1<<n); i++) {
            t = (i>>1)^i;
            ans.push_back(t);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x;
    cin >> x;
    vector<int> ans = sol.grayCode(x);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    return 0;
}
