/* LC ID :  #126
 * Type  :  BFS
 * Author:  Hangchen Yu
 * Date  :  07/30/2015
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
    vector<vector<string> > ans;
    vector<string> path;
    typedef struct {
        vector<string> father;
        int            depth;
    } Node;
    unordered_map<string, Node> pre;

    void print_path(string now, const string &start) { /* print the path */
        path.push_back(now);
        if (now != start) {
            unordered_map<string, Node>::const_iterator tmp = pre.find(now);
            for (int i = 0; i < tmp->second.father.size(); i++)
                    print_path(tmp->second.father[i], start);
        }
        else {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        ans.clear();
        if (start == end) return ans;

        queue<string>         que;
        queue<int>            depth;
        unordered_map<string, Node>::const_iterator mit;
        Node node;
        vector<string>        t_node;
        bool                  flag;

        int    len = start.length();
        string now, backup, tmp;
        int    len_ans = -1, len_now;
        que.push(start);
        depth.push(0);
        node.depth = 0; node.father.clear(); pre.insert({start, node});

        while (!que.empty()) {
            now = que.front();
            que.pop();
            len_now = depth.front();
            if (len_ans >= 0 && len_now > len_ans || len_now > dict.size()) break;
            depth.pop();

            backup = now;
            flag   = false;
            for (int i = 0; i < len; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == backup[i]) continue;
                    now[i] = j;

                    if (now == end) { /* find the `end` */
                        len_ans = len_now;
                        path.clear();
                        path.push_back(end);
                        print_path(backup, start);
                        flag = true;
                        break;
                    }

                    mit = pre.find(now);
                    if (dict.find(now) != dict.end() &&
                        (mit == pre.end() || (mit != pre.end() && mit->second.depth == len_now +1))
                        ) { /* push in the queue */
                            /* update pre begin */
                            node.depth = len_now + 1;
                            if (mit == pre.end()) {
                                t_node.clear();
                                t_node.push_back(backup);
                                que.push(now);
                                depth.push(len_now+1);
                            }
                            else {
                                t_node = mit->second.father;
                                t_node.push_back(backup);
                            }
                            node.father = t_node;
                            pre.erase(now);
                            pre.insert({now, node});
                            /* update pre end */
                    }
                }
                if (flag) break;
                now = backup;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> ans = sol.findLadders("red", "tax", dict);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
