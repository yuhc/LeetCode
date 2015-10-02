/* LC ID :  #73
 * Type  :  Enumerate
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
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
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) return;
        int m = matrix[0].size();

        bool firstrow = false, firstcol = false;
        for (int i = 0; i < m; i++)
            if (!matrix[0][i]) firstrow = true;
        for (int i = 0; i < n; i++)
            if (!matrix[i][0]) firstcol = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
        if (firstrow)
            for (int i = 0; i < m; i++) matrix[0][i] = 0;
        if (firstcol)
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> num;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; vector<int> t;
        for (int j = 0; j < m; j++) {
            cin >> x;
            t.push_back(x);
        }
        num.push_back(t);
    }
    sol.setZeroes(num);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << num[i][j] << " ";
        cout << endl;
    }

    return 0;
}
