/* LC ID :  #28
 * Type  :  Substring
 * Author:  Hangchen Yu
 * Date  :  05/08/2015
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
    void computeNextArray(string pattern, int *next) {
        int len = 0;    // length of previous longest prefix suffix
        next[0] = 0;    // next[0] is always 0
        int i = 1;

        while (i < pattern.length()) {
            if (pattern[i] == pattern[len]) {
                len++;
                next[i++] = len;
            }
            else {
                if (len != 0)
                    len = next[len-1];
                else
                    next[i++] = 0;
            }
        }
    }

    int KMPSearch(string text, string pattern, int *next) {
        int len_t = text.length(), len_p = pattern.length();
        int i = 0, j = 0;

        while (i < len_t) {
            if (text[i] == pattern[j]) {
                i++; j++;
            }
            else {
                if (j != 0)
                    j = next[j-1];
                else
                    i++;
            }

            if (j == len_p) {
                return i-j;
                //j = next[j-1];  if want to find all matched patterns
            }
            if (i == len_t) return -1;   // not found
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;

        int next[needle.length()];
        computeNextArray(needle, next);
        return KMPSearch(haystack, needle, next);
    }
};

int main() {
    Solution sol;
    string x, y;
    cin >> x >> y;
    y = "";
    cout << sol.strStr(x, y) << endl;

    return 0;
}
