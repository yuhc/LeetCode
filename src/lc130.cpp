/* LC ID :  #130
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
    void solve(vector<vector<char>>& board) {
        struct Point {
            int x, y;
            Point(int a, int b): x(a), y(b) {}
        };
        queue<Point> q;
        int n = board.size();
        if (!n) return;
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                q.push(Point(i,0));
            if (board[i][m-1] == 'O' && m != 1)
                q.push(Point(i,m-1));
        }
        for (int j = 1; j < m; j++) {
            if (board[0][j] == 'O')
                q.push(Point(0,j));
            if (board[n-1][j] == 'O' && n != 1)
                q.push(Point(n-1,j));
        }

        int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while (!q.empty()) {
            Point now = q.front();
            q.pop();
            board[now.x][now.y] = 'T';
            for (int k = 0; k < 4; k++) {
                int x = now.x+d[k][0], y = now.y+d[k][1];
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
                    q.push(Point(x,y));
                }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
    }
};

int main() {
    Solution sol;
    

    return 0;
}
