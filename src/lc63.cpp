/* LC ID :  #63
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int f[n][m];
        f[0][0] = 1;
        for (int i = 1; i < n; i++)
            if (obstacleGrid[i][0]) f[i][0] = 0;
            else f[i][0] = f[i-1][0];
        for (int i = 1; i < m; i++)
            if (obstacleGrid[0][i]) f[0][i] = 0;
            else f[0][i] = f[0][i-1];

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (obstacleGrid[i][j]) f[i][j] = 0;
                else f[i][j] = f[i-1][j] + f[i][j-1];

        return f[n-1][m-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> data = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePathsWithObstacles(data) << endl;

    return 0;
}
