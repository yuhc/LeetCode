/* LC ID :  #62
 * Type  :  Math
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
    int uniquePaths(int m, int n) {
        int f[m][n];
        for (int i = 0; i < m; i++) f[i][0] = 1;
        for (int i = 0; i < n; i++) f[0][i] = 1;
        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1];
        return f[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int n, m;
    cin >> m >> n;
    cout << sol.uniquePaths(m, n) << endl;

    return 0;
}
