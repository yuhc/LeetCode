/* LC ID :  #20
 * Type  :  Stack
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
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
    bool isValid(string s) {
        if (s.empty()) return true;

        stack<char> op;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case ')':
                    if (op.empty() || op.top() != '(')
                        return false;
                    else op.pop();
                    break;
                case ']':
                    if (op.empty() || op.top() != '[')
                        return false;
                    else op.pop();
                    break;
                case '}':
                    if (op.empty() || op.top() != '{')
                        return false;
                    else op.pop();
                    break;
                default:
                    op.push(s[i]);
            }
        }
        return op.empty();
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.isValid(s) << endl;

    return 0;
}
