/* LC ID :  #32
 * Type  :  Dynamic Programming
 * Author:  Hangchen Yu
 * Date  :  06/27/2015
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

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int f[len], best = 0;
        memset(f, 0, sizeof(f));

        for (int i = len-1; i >= 0; i--) {
            // (...)
            if (i < len - 2 && s[i] == '(' && s[i+1+f[i+1]] == ')')
                f[i] = max(f[i], f[i+1]+2);
            // (...)(...)
            if (f[i] > 0 && f[i+f[i]] > 0)
                f[i] = max(f[i], f[i]+f[i+f[i]]);
                
            best = max(best, f[i]);
        }

        return best;
    }
};

class Solution_TLE {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        bool f[len][len];
        memset(f, false, sizeof(f));

        for (int l = 2; l <= len; l+=2)
            for (int i = 0; i < len+1-l; i++) {
                int j = i + l - 1;

                // (...)
                if (s[i] == '(' && s[j] == ')' && (l == 2 || f[i+1][j-1])) {
                    f[i][j] = true;
                    continue;
                }
                // ()(...)
                for (int k = i+2; k < j; k += 2)
                    if (f[i][k-1] && f[k][j]) {
                        f[i][j] = true;
                        break;
                    }
                }

        int ans = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j += 2)
                if (f[i][j] && j - i + 1 > ans)
                    ans = j - i + 1;

        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestValidParentheses(s) << endl;

    return 0;
}
