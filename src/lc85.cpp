/* LC ID :  #85
 * Type  :  Dynamic Programming
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int height[m];
        memset(height, 0, sizeof(height));
        int best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j]++;
            }

            int left, right;
            for (int j = 0; j < m; j++) {
                left = right = j;
                while (left > 0 && height[j] <= height[left-1]) left--;
                while (right < m-1 && height[j] <= height[right+1]) right++;
                best = max((right-left+1)*height[j], best);
            }
        }

        return best;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
