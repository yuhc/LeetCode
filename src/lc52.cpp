/* LC ID :  #52
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
    int totalNQueens(int n) {
        if (!n) return 0;
        int tot = 0;
        dfs(0, tot, 0, 0, 0, n);
        return tot;
    }

    void dfs(int x, int& tot, int col, int dia1, int dia2, int n) {
        if (x == n) {
            tot++;
            return;
        }

        for (int y = 0; y < n; y++)
            if (!(col&(1<<y)) && !(dia1&(1<<(x+y))) && !(dia2&(1<<(n-1-x+y)))) {
                dfs(x+1, tot, col|(1<<y), dia1|(1<<(x+y)), dia2|(1<<(n-1-x+y)), n);
            }
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.totalNQueens(n) << endl;

    return 0;
}
