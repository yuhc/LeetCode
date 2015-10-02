/* LC ID :  #91
 * Type  :  Dynamic Programming
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
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int f[s.length()+1];
        f[0] = f[1] = 1;
        for (int i = 2; i <= s.length(); i++) {
            int t = (s[i-2]-'0')*10+(s[i-1]-'0');
            if (s[i-1] == '0' && (!t || t > 26)) return 0;
            if (s[i-1] == '0' || t < 10) f[i] = f[i-2];
            else {
                if (t > 10 && t <= 26) f[i] = f[i-1]+f[i-2];
                else f[i] = f[i-1];
            }
        }
        return f[s.length()];
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.numDecodings(s) << endl;

    return 0;
}
