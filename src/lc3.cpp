/* LC ID :  #1
 * Type  :  
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
 */
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
    int lengthOfLongestSubstring(string s) {
        bool flag[1000];
        memset(flag, false, sizeof(flag));
        int l = 0, t, ans = 0, tot = 0;

        for (int r = 0; r < s.size(); r++) {
            t = int(s[r]);
            if (!flag[t]) {
                tot++;
                flag[t] = true;
                if (tot > ans) ans = tot;
                continue;
            }

            while (l < r && s[l] != s[r]) {
                flag[int(s[l++])] = false;
                tot--;
            }
            l++;
        }

        return ans;
    }
};

int main() {
    Solution ss;
    string s = "abcabcbb";
    cout << ss.lengthOfLongestSubstring(s) << endl;
    return 0;
}
