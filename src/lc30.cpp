/* LC ID :  #30
 * Type  :  Substring, Two Pointers
 * Author:  Hangchen Yu
 * Date  :  05/13/2015
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
        int i   = 1;

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

    void KMPSearch(string s, string pattern, int pattern_id, int *match) {
        int next[pattern.length()];
        memset(next, 0, sizeof(next));
        computeNextArray(pattern, next);

        int len_s = s.length(), len_p = pattern.length();
        int i = 0, j = 0;

        while (i < len_s) {
            if (s[i] == pattern[j]) {
                i++; j++;
            }
            else {
                if (j != 0)
                    j = next[j-1];
                else
                    i++;
            }

            if (j == len_p) {
                match[i-j] = pattern_id;
                j = next[j-1];
            }
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        if (s.length() < words.size()*words[0].length()) return ans;

        int match[s.length()];
        const int num_w = words.size();
        memset(match, -1, sizeof(match));
        // KMP
        for (int i = 0; i < num_w; i++)
            KMPSearch(s, words[i], i, match);
        
        // Duplicates, can use Hash
        int maxnum[num_w];
        memset(maxnum, 0, sizeof(maxnum));
        for (int i = 0; i < num_w; i++)
            for (int j = i; j < num_w; j++)
                if (words[i] == words[j])
                    maxnum[j]++;
        
        // Two pointers
        int       l, r;
        const int len_w = words[0].length();
        int       bj[num_w];
        for (int start = 0; start < len_w; start++) {
            l = r = start;
            memset(bj, 0, sizeof(bj));
            while (l <= s.length()-len_w*num_w) {
                if (match[r] < 0) {
                    memset(bj, 0, sizeof(bj));
                    l = (r += len_w);
                }
                else if (bj[match[r]] >= maxnum[match[r]]) {
                    while (match[l] != match[r]) {
                        bj[match[l]]--;
                        l += len_w;
                    }
                    l += len_w; r += len_w;
                }
                else {
                    bj[match[r]]++;
                    r += len_w;
                }

                if (r-l == len_w*num_w) {
                    ans.push_back(l);
                    bj[match[l]]--;
                    l += len_w;
                }
            }

        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    int n; string x;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        cin >> x;
        words.push_back(x);
    }
    vector<int> ans = sol.findSubstring(s, words);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
