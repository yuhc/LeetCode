/* LC ID :  #64
 * Type  :  Dynamic Programming
 * Author:  Hangchen Yu
 * Date  :  09/10/2015
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
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int f[n][m];
        memset(f, 0, sizeof(f));
        f[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) f[i][0] = f[i-1][0] + grid[i][0];
        for (int i = 1; i < m; i++) f[0][i] = f[0][i-1] + grid[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];

        return f[n-1][m-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> data = {{1, 2, 1}, {3, 0, 1}, {1, 2, 0}};
    cout << sol.minPathSum(data) << endl;

    return 0;
}
