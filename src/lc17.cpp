/* LC ID :  #1
 * Type  :  
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
    vector<string> ans;
    string tmp;

    void dfs(int n, int k, string &digits) {
        if (k == digits.length()) {
            ans.push_back(tmp);
            return;
        }

        if (digits[k] == '0') {
            if (tmp.length() > n) tmp[n] = ' ';
            else tmp += ' ';
            dfs(n+1, k+1, digits);
            return;
        }
        else if (digits[k] == '1') {
            dfs(n, k+1, digits);
            return;
        }

        for (int i = 0; i < ((digits[k]=='7'||digits[k]=='9')?4:3); i++) {
            if (tmp.length() > n)
                tmp[n] = char('a'+(digits[k]-'0')*3-6+i+(digits[k]>'7'));
            else
                tmp += char('a'+(digits[k]-'0')*3-6+i+(digits[k]>'7'));
            dfs(n+1, k+1, digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(0, 0, digits);
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    vector<string> ss = sol.letterCombinations(s);
    for (int i = 0; i < ss.size(); i++) {
        cout << ss[i] << endl;
    }

    return 0;
}
