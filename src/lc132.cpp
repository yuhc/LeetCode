/* LC ID :  #132
 * Type  :  String + Dynamic Programming
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
    int minCut(string s) {
        if (s.empty()) return 0;

        int n = s.length();
        bool **isPalin = (bool**)malloc(n*sizeof(bool*));
        for (int i = 0; i < n; i++)
            isPalin[i] = (bool*)malloc(n*sizeof(bool));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) isPalin[i][j] = false;

        //char as center
        for (int i = 0; i < n; i++) isPalin[i][i] = true;
        for (int i = 1; i < n-1; i++)
            for (int l = 1; l <= min(i,n-i-1); l++)
                if (s[i-l] == s[i+l]) isPalin[i-l][i+l] = true;
                else break;
        //slot as center
        for (int i = 0; i < n-1; i++)
            for (int l = 1; l <= min(i+1,n-i-1); l++)
                if (s[i-l+1] == s[i+l]) isPalin[i-l+1][i+l] = true;
                else break;

        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            f[i] = n;
            if (isPalin[0][i]) f[i] = 1;
            else
                for (int j = 0; j < i; j++)
                    if (isPalin[j+1][i] && f[j]+1 < f[i])
                        f[i] = f[j] + 1;
        }
        return f[n-1]-1;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.minCut(s) << endl;

    return 0;
}
