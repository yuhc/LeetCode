/* LC ID :  #38
 * Type  :  Recursive
 * Author:  Hangchen Yu
 * Date  :  09/03/2015
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
    string construct(int k, string s, int n) {
        if (k == n) return s;

        string t = "";
        for (int i = 0; i < s.length(); i++) {
            int count = 1;
            while (i < s.length() && s[i] == s[i+1]) {
                count++; i++;
            }
            string tmp = "";
            while (count > 0) {
                tmp = char((count%10) + '0') + tmp;
                count /= 10;
            }
            t += tmp + s[i];
        }

        return construct(k+1, t, n);
    }

    string countAndSay(int n) {
        if (!n) return "";
        return construct(1, "1", n);
    }

};

int main() {
    Solution sol;
    for (int n = 0; n <= 20; n++) cout << "n = " << n << ":\t" << sol.countAndSay(n) << endl;

    return 0;
}
