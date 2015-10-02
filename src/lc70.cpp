/* LC ID :  #70
 * Type  :  Math
 * Author:  Hangchen Yu
 * Date  :  09/11/2015
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
    int climbStairs(int n) {
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < n-1; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.climbStairs(n) << endl;

    return 0;
}
