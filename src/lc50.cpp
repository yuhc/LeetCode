/* LC ID :  #50
 * Type  :  Mathematics
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
    double sol(double x, unsigned int n) {
        if (!n) return 1;
        double t = sol(x, n>>1);
        if (n&1) return x*t*t;
        else return t*t;
    }

    double myPow(double x, int n) {
        if (!n) {
            if (x == 0) return 0;
            else return 1;
        }

        bool bj = false;
        unsigned int k;
        if (n < 0) {
            bj = true;
            k = -n;
        }
        else k = n;
        double ans = sol(x, k);
        if (!bj) return ans;
        else return 1/ans;
    }
};

int main() {
    Solution sol;
    double x; int n;
    cin >> x >> n;
    cout << sol.myPow(x, n) << endl;

    return 0;
}
