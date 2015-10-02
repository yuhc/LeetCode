/* LC ID :  #139
 * Type  :  Dynamic Programming
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
#include <unordered_set>
#include <utility>
#include <cmath>

using namespace std;

//copy the Solution class here
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        bool canBreak[n]; //right-side
        memset(canBreak, false, sizeof(canBreak));
        canBreak[n] = true;
        for (int i = n-1; i >= 0; i--)
            for (int j = 1; j <= n-i; j++)
                if (canBreak[i+j] && wordDict.count(s.substr(i,j))) {
                    canBreak[i] = true;
                    break;
                }

        return canBreak[0];
    }
};

int main() {
    Solution sol;
    string s;
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    //s = "abcd";
    //unordered_set<string> wordDict = {"a","abc","b","cd"};
    cout << sol.wordBreak(s, wordDict) << endl;

    return 0;
}
