/* LC ID :  #51
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/09/2015
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (!n) return ans;
        int pos[n];
        dfs(0, pos, ans, 0, 0, 0, n);
        return ans;
    }

    void dfs(int x, int pos[], vector<vector<string>>& ans, int col, int dia1, int dia2, int n) {
        if (x == n) {
            vector<string> tmp;
            string s;
            for (int i = 0; i < n; i++) {
                s = "";
                for (int j = 0; j < n; j++)
                    if (j != pos[i]) s += '.';
                    else s += 'Q';
                tmp.push_back(s);
            }
            ans.push_back(tmp);
            return;
        }

        for (int y = 0; y < n; y++)
            if (!(col&(1<<y)) && !(dia1&(1<<(x+y))) && !(dia2&(1<<(n-1-x+y)))) {
                pos[x] = y;
                dfs(x+1, pos, ans, col|(1<<y), dia1|(1<<(x+y)), dia2|(1<<(n-1-x+y)), n);
            }
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<string>> ans = sol.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << endl;
        cout << endl;
    }

    return 0;
}
