/* LC ID :  #54
 * Type  :  Simulation
 * Author:  Hangchen Yu
 * Date  :  09/08/2015
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int m = matrix.size(), n = matrix[0].size();
        int x, y, k, count;
        x = y = k = count = 0;
        int state = 0; //0:right, 1:down, 2:left, 3:up
        while (count < n * m) {
            cout << "# " << state << endl;
            ans.push_back(matrix[x][y]);
            count++;

            switch (state) {
                case 0:
                    if (y == n-k-1) state++;
                    break;
                case 1:
                    if (x == m-k-1) state++;
                    break;
                case 2:
                    if (y == k) state++;
                    break;
                case 3:
                    if (x == k+1) {
                        state = 0;
                        k++;
                    }
            }

            switch (state) {
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> num;
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            cin >> x;
            tmp.push_back(x);
        }
        num.push_back(tmp);
    }

    vector<int> ans = sol.spiralOrder(num);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;

    return 0;
}
