/* LC ID :  #37
 * Type  :  DFS, Hash
 * Author:  Hangchen Yu
 * Date  :  09/06/2015
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
    bool dfs(int x, int y, vector<vector<char>>& board, int row[], int col[], int sqr[]) {
        if (x >= 9) return true;

        if (board[x][y] != '.') {
            if (y == 8)
                return dfs(x+1, 0, board, row, col, sqr);
            else
                return dfs(x, y+1, board, row, col, sqr);
        }
        else {
            for (int i = 0; i < 9; i++) {
                int t = 1 << i;
                if (!(row[x]&t) && !(col[y]&t) && !(sqr[x/3*3+y/3]&t)) {
                    board[x][y] = '1' + i;
                    row[x] ^= t; col[y] ^= t; sqr[x/3*3+y/3] ^= t;
                    if (y == 8) {
                        if (dfs(x+1, 0, board, row, col, sqr)) return true;
                    }
                    else {
                        if (dfs(x, y+1, board, row, col, sqr)) return true;
                    }
                    board[x][y] = '.';
                    row[x] ^= t; col[y] ^= t; sqr[x/3*3+y/3] ^= t;
                }
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int row[9], col[9], sqr[9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(sqr, 0, sizeof(sqr));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int t =  1 << (board[i][j]-'1');
                    row[i] |= t; col[j] |= t; sqr[i/3*3+j/3] |= t;
                }

        dfs(0, 0, board, row, col, sqr);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board;
    char c;
    for (int i = 0; i < 9; i++) {
        vector<char> tmp;
        tmp.clear();
        for (int j = 0; j < 9; j++) {
            scanf("%c", &c);
            tmp.push_back(c);
        }
        board.push_back(tmp);
        if (i != 8) scanf("\n");
    }

    sol.solveSudoku(board);

    printf("\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }

    return 0;
}

/*
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
 */
