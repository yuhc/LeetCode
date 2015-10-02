/* LC ID :  #9
 * Type  :  N/A
 * Author:  Hangchen Yu
 * Date  :  04/18/2015
 */
#include <cstdio>
#include <iostream>
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
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        
        int div = 1;
        while (x/div >= 10)
            div *= 10;

        while (x > 0) {
            if (x%10 != x/div) return false;
            x %= div;
            x /= 10;
            div /= 100;
        }
        return true;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.isPalindrome(n) << endl;
    return 0;
}
