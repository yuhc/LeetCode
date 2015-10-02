/* LC ID :  #5
 * Type  :  Longest Palindromic Substring
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>

// Manacher's algorithm
// http://en.wikipedia.org/wiki/Longest_palindromic_substring

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string addBoundaries(string s) {
        string s2 = "";
        for (int i = 0; i < s.length(); i++) {
            s2 += "|";
            s2 += s[i];
        }
        s2 += '|';
        return s2;
    }

    string removeBoundaries(string s) {
        string s0 = "";
        for (int i = 0; i < s.length(); i++)
            if (s[i] != '|')
                s0 += s[i];
        return s0;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string s2 = addBoundaries(s);
        int p[s2.length()];
        memset(p, 0, sizeof(p));
        int c = 0, r = 0;   // Here the first element in s2 has been processed
        int m = 0, n = 0;   // The walking indices to compare if two elements are the same
        for (int i = 1; i < s2.length(); i++) {
            if (i > r) {
                // Case 3: outside the rightmost of reference
                p[i] = 0; m = i-1; n = i+1;
            }
            else {
                int i2 = c*2-i; // Mirror of i
                if (p[i2] < r-i) {
                    // Case 1: inside the right part of reference
                    p[i] = p[i2];
                    m = -1;     // This signals bypassing the while loop below
                }
                else {
                    // Case 2: Expend
                    p[i] = r-i;
                    n = r+1; m = (i<<1)-n;
                }
            }

            while (m >= 0 && n < s2.length() && s2[m] == s2[n]) {
                p[i]++; m--; n++;
            }

            // Update the reference
            if (i+p[i] > r) {
                c = i; r = i+p[i];
            }
        }

        int len = 0; c = 0;
        for (int i = 0; i < s2.length(); i++)
            if (p[i] > len) {
                len = p[i]; c = i;
            }

        return removeBoundaries(s2.substr(c-len, len*2+1));
    }
};

int main() {
    Solution sol;
    string s;
    std::cin >> s;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
