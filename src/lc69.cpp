/* LC ID :  #69
 * Type  :  Binary Search
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
    int mySqrt(int x) {
        if (x < 0) return (1<<(sizeof(int)*8)-1);

        unsigned int l = 0, r = 1<<(sizeof(int)*4);
        unsigned int mid = (l+r) >> 1;
        while (l < r) {
            if (mid*mid > x) r = mid - 1;
            else if (mid*mid < x) {
                if ((mid+1)*(mid+1) > x) return mid;
                else l = mid + 1;
            }
            else return mid;
            mid = (l+r) >> 1;
        }
        return l;
    }
};

int main() {
    Solution sol;
    int x;
    cin >> x;
    cout << sol.mySqrt(x) << endl;

    return 0;
}
