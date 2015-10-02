/* LC ID :  #71
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/11/2015
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
    string simplifyPath(string path) {
        path += '/';
        int k = 0, len = path.length();
        vector<string> list;
        string s;
        while (k < len) {
            while (k < len && path[k] == '/') k++;
            s = "";

            //dot
            if (path.substr(k, 2) == "./") { k += 2; continue; }
            if (path.substr(k, 3) == "../") {
                k += 3;
                if (!list.empty()) list.pop_back();
                continue;
            }

            //pathname
            while (k < len && path[k] != '/') s += path[k++];
            if (!s.empty()) list.push_back(s);
        }

        if (list.empty()) return "/";
        s = "";
        for (int i = 0; i < list.size(); i++)
            s += '/' + list[i];
        return s;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.simplifyPath(s) << endl;

    return 0;
}
