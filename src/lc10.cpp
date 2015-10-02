/* LC ID :  #10
 * Type  :  String Matching
 * Author:  Hangchen Yu
 * Date  :  04/18/2015
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
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        // abc ==> _*
        if (p.length() > 1 && p[1] == '*') {
            int i = 0;
            while (i < s.length() && (s[i] == p[0] || p[0] == '.')) {
                if (isMatch(s.substr(i, s.length()-i), p.substr(2, p.length()-2)))
                    return true;
                    i++;
                }
            return (isMatch(s.substr(i, s.length()-i), p.substr(2, p.length()-2)));
        }
        else {
            // abc ==> _
            if (s.empty()) return false;
            if (s[0] != p[0] && p[0] != '.') return false;
            if (!(isMatch(s.substr(1, s.length()-1), p.substr(1, p.length()-1))))
                return false;
            return true;
        }
    }
};

int main() {
    Solution sol;
    string s, p;
    cin >> s;
    cin >> p;
    cout << sol.isMatch(s, p) << endl;

    return 0;
}
