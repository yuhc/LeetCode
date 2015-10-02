/* LC ID :  #74
 * Type  :  Binary Search
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();

        struct Point {
            int x, y;
            Point(int a, int b) : x(a), y(b) {}
            Point() : x(0), y(0) {}
        } left(0, 0), right(n-1, m-1), mid;

        int id = ((left.x*m+left.y) + (right.x*m+right.y)) >> 1;
        mid.x = id/m; mid.y = id-id/m*m;
        while (left.x < right.x || (left.x == right.x && left.y <= right.y)) {
            if (matrix[mid.x][mid.y] > target) {
                right = mid;
                if (mid.y == 0) right.x--;
                right.y = (right.y+m-1)%m;
            }
            else if (matrix[mid.x][mid.y] < target) {
                left = mid;
                if (mid.y == m-1) left.x++;
                left.y = (left.y+1)%m;
            }
            else return true;

            id = ((left.x*m+left.y) + (right.x*m+right.y)) >> 1;
            mid.x = id/m; mid.y = id-id/m*m;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> num;
    int n, m, ta;
    cin >> n >> m >> ta;
    for (int i = 0; i < n; i++) {
        int x; vector<int> t;
        for (int j = 0; j < m; j++) {
            cin >> x;
            t.push_back(x);
        }
        num.push_back(t);
    }
    cout << sol.searchMatrix(num, ta) << endl;

    return 0;
}
