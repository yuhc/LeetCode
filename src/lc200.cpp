/* LC ID :  #200
 * Type  :  BFS
 * Author:  Hangchen Yu
 * Date  :  09/22/2015
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
#include <climits>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL),
    next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        struct Point {
            int x, y;
            Point(int a, int b): x(a), y(b) {}
        };
        queue<Point> q;
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();

        int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    q.push(Point(i,j));
                    grid[i][j] = '0';
                    count++;
                    while (!q.empty()) {
                        Point now = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = now.x+d[k][0], y = now.y+d[k][1];
                            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1') {
                                q.push(Point(x,y));
                                grid[x][y] = '0';
                            }
                        }
                    }
                }

        return count;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
