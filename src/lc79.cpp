/* LC ID :  #79
 * Type  :  DFS
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
    const short d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    bool dfs(int x, int y, int k, int n, int m, vector<vector<char>>& board, string& word) {
        if (k == word.length()) return true;

        char tmp = board[x][y];
        board[x][y] = '*';
        for (int i = 0; i < 4; i++) {
            int xx = x+d[i][0], yy = y+d[i][1];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && board[xx][yy] == word[k]) {
                if (k == word.length()-1) return true;
                if (dfs(xx, yy, k+1, n, m, board, word))
                    return true;
            }
        }
        board[x][y] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (!n) return false;
        int m = board[0].size();
        if (word.length() > n*m) return false;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    if (dfs(i, j, 1, n, m, board, word)) return true;
        return false;
    }
};

int main() {
    Solution sol;
    //vector<char> r1 = {'A','B','C','E'};
    //vector<char> r2 = {'S','F','C','S'};
    //vector<char> r3 = {'A','D','E','E'};
    vector<char> r;
    for (int i = 0; i < 30; i++) r.push_back('a');
    vector<vector<char>> b;
    //b.push_back(r1); b.push_back(r2); b.push_back(r3);
    for (int i = 0; i < 29; i++) b.push_back(r);
    r.pop_back(); r.push_back('b');
    b.push_back(r);
    string s;
    cin >> s;
    cout << sol.exist(b, s) << endl;

    return 0;
}
