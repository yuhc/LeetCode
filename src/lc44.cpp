/* LC ID :  #44
 * Type  :  Backtrace
 * Author:  Hangchen Yu
 * Date  :  09/07/2015
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
//or use Dynamic Programming:
//bool f[i][j]: whether can p[0:i] match s[0:j]
//f[i][] is only related to f[i-1][]
class Solution {
public:
    bool isMatch(string s, string p) {
        if (!s.empty() && p.empty()) return false;
        int i, j, sStar = -1, pStar = -1;

        for (i = 0, j = 0; i < s.length(); i++, j++) {
            if (p[j] == '*') {
                sStar = i;
                pStar = j;
                i--;
            }
            else if (s[i] != p[j] && p[j] != '?' || j >= p.length()) { // Mismatch
                if (sStar < 0) return false;
                i = sStar++;
                j = pStar;
            }
        }

        while (j < p.length() && p[j] == '*') j++;
        return (j == p.length());
    }
};

int main() {
    Solution sol;
    string a, b;
    a = "aa"; b = "a"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "aa"; b = "aa"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "aaa"; b = "aa"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "aa"; b = "*"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "aa"; b = "a*"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "ab"; b = "?*"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = "aab"; b = "c*a*b"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = ""; b = ""; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;
    a = ""; b = "*"; cout << "a: " << a << ";\tb: " << b << ";\t" << sol.isMatch(a, b) << endl;

    return 0;
}
