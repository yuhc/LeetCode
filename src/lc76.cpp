/* LC ID :  #76
 * Type  :  Two pointer
 * Author:  Hangchen Yu
 * Date  :  09/14/2015
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
    string minWindow(string s, string t) {
        int chtable[256];
        memset(chtable, 0, sizeof(chtable));
        for (int i = 0; i < t.length(); i++) chtable[t[i]]++;
        int chnum = 0;
        for (int i = 0; i < 256; i++)
            chnum += chtable[i];

        //find the first window
        int left = 0;
        while (left < s.length() && !chtable[s[left]]) left++;
        int right = left;
        int chcount[256];
        memset(chcount, 0, sizeof(chcount));
        while (right < s.length() && chnum > 0) {
            if (chtable[s[right]]) {
                if (chcount[s[right]] < chtable[s[right]]) chnum--;
                chcount[s[right]]++;
                if (!chnum) break;
            }
            right++;
        }
        if (right >= s.length()) return "";

        //adjust the window
        int best = right-left+1, pos = left;
        while (right < s.length()) {
            if (chtable[s[left]] && chcount[s[left]] == chtable[s[left]]) {
                right++;
                while (right < s.length() && s[right] != s[left]) {
                    chcount[s[right]]++;
                    right++;
                }
            }
            else if (chtable[s[left]] && chcount[s[left]] > chtable[s[left]])
                chcount[s[left]]--;
            left++;
            if (left >= s.length() || right >= s.length()) break;
            if (right-left+1 < best) {
                best = right-left+1;
                pos = left;
            }
        }

        return s.substr(pos, best);
    }
};

int main() {
    Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.minWindow(s, t) << endl;

    return 0;
}
