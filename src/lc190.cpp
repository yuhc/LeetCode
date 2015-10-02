/* LC ID :  #190
 * Type  :  Bit Manipulation
 * Author:  Hangchen Yu
 * Date  :  09/28/2015
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
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        for (int i = 0; i < 32; i++) {
            r <<= 1;
            r |= (n&1);
            n >>= 1;
        }
        return r;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
