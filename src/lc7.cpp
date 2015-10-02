/* LC ID :  #7
 * Type  :  Enumeration
 * Author:  Hangchen Yu
 * Date  :  04/17/2015
 */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <cmath>

using std::swap;
using std::vector;
using std::pair;

//copy the Solution class here
class Solution {
public:
    int reverse(int x) {
        bool sign = x < 0;
        int sign_d = x & (1<<31);
        if (!x) return 0;
        else if (x < 0) x = -x;
        
        while (x%10 == 0) x /= 10;
        long t = 0;
        while (x > 0) {
            t = t*10 + x%10;
            x /= 10;
        }
        if (sign) t = -t;

        if ((t&(1<<31)) ^ sign_d) return 0; //overflow
        return t;
    }
};

int main() {
    Solution s;
    int x;
    std::cin >> x;
    printf("%d\n", s.reverse(x));
    return 0;
}
