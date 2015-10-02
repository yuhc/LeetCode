/* LC ID :  #59
 * Type  :  Array
 * Author:  Hangchen Yu
 * Date  :  09/09/2015
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
    bool valid(int x, int y, vector<vector<int>>& m) {
        if (x < 0 || y < 0 || x >= m.size() || y >= m.size()) return false;
        if (m[x][y] != 0) return false;
        return true;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x, y, d;

        x = y = d = 0;
        for (int k = 1; k <= n*n; k++) {
            ans[x][y] = k;
            if (!valid(x+dir[d][0], y+dir[d][1], ans))
                d = (d+1) % 4;
            x += dir[d][0];
            y += dir[d][1];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> ans = sol.generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
