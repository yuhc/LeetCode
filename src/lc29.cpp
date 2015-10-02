/* LC ID :  #29
 * Type  :  Bit operation
 * Author:  Hangchen Yu
 * Date  :  05/08/2015
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
    int divide(int dividend, int divisor) {
        if (!divisor) return INT_MAX;

        unsigned int u_dividend, u_divisor;
        int sign = 0;
        if (dividend < 0) { u_dividend = -dividend; sign++; }
        else u_dividend = dividend;
        if (divisor < 0) { u_divisor = -divisor; sign++; }
        else u_divisor = divisor;

        unsigned int ans = 0, d = u_divisor, shift = 1;
        while (d <= INT_MAX && (d << 1) <= u_dividend) {
            d <<= 1;
            shift <<= 1;
        }

        while (u_dividend >= u_divisor) {
            u_dividend -= d;
            ans += shift;
            while (d > u_dividend) {
                d >>= 1;
                shift >>= 1;
            }   
        }

        if (sign != 1 && ans > INT_MAX) return INT_MAX;
        return (sign == 1) ? -ans : ans;
    }
};

int main() {
    Solution sol;
    int x, y;
    cin >> x >> y;
    cout << sol.divide(x, y) << endl;

    return 0;
}
