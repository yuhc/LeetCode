/* LC ID :  #127
 * Type  :  BFS
 * Author:  Hangchen Yu
 * Date  :  07/31/2015
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
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) return 1;

        int                   ans;
        queue<string>         que;
        queue<int>            depth;
        bool                  flag;
        unordered_set<string> visited;
        int                   len = beginWord.length();
        string                now, backup;
        int                   len_now;

        que.push(beginWord);
        depth.push(1);
        visited.insert(beginWord);

        while (!que.empty()) {
            now = que.front();
            que.pop();
            len_now = depth.front();
            if (len_now > wordDict.size()) break;
            depth.pop();

            backup = now;
            flag   = false;
            for (int i = 0; i < len; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == backup[i]) continue;
                    now[i] = j;

                    if (now == endWord) { /* find the `end` */
                        return len_now + 1;
                    }

                    if (wordDict.find(now) != wordDict.end() && visited.find(now) == visited.end()) { /* push in the queue */
                        que.push(now);
                        depth.push(len_now+1);
                        visited.insert(now);
                    }
                }
                if (flag) break;
                now = backup;
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", dict) << endl;

    return 0;
}
