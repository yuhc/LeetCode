/* LC ID :  #6
 * Type  :  Numeration
 * Author:  Hangchen Yu
 * Date  :  04/16/2015
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

using std::cin;
using std::cout;
using std::string;

//copy the Solution class here
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 2) return s;

        int period = nRows*2-2;
        string ans = "";
        //first row
        for (int i = 0; i < s.length(); i+=period)
            ans += s[i];
        //middle rows
        for (int start = 1; start < nRows-1 && start < s.length(); start++) {
            for (int i = start; i < s.length(); i+=period) {
                ans += s[i];
                if (i+period-start*2 < s.length())
                    ans += s[i-start+period-start];
            }
        }
        //last row
        for (int i = nRows-1; i < s.length(); i+=period)
            ans += s[i];

        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    int n;
    cin >> s;
    cin >> n;
    cout << sol.convert(s, n) << "\n";
    return 0;
}
