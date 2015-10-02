/* LC ID :  #65
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/10/2015
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
    bool isNumber(string s) {
        int k = 0;
        //space
        while (k < s.length() && s[k] == ' ') k++;
        if (k == s.length()) return false;

        //sign
        if (s[k] == '+' || s[k] == '-') k++;
        if (k == s.length() || ((s[k] > '9' || s[k] < '0') && (s[k] != '.'))) return false;

        //before dot
        while (k < s.length() && s[k] >= '0' && s[k] <= '9') k++;
        if (k == s.length()) return true;

        //dot
        if (s[k] == '.') {
            if ((!k || s[k-1] == ' ' || s[k-1] == '+' || s[k-1] == '-') && (k == s.length()-1 || s[k+1] == ' ' || s[k+1] == 'e' || s[k+1] == 'E')) return false; //single dot
            if (++k == s.length()) return true;
            if (s[k] != ' ' && s[k] != 'e' && s[k] != 'E' && (s[k] > '9' || s[k] < '0')) return false;
        }
        while (k < s.length() && s[k] >= '0' && s[k] <= '9') k++;

        //exp
        if (s[k] == 'e' || s[k] == 'E') {
            if (++k == s.length()) return false;
            if (s[k] == '+' || s[k] == '-') k++;
            if (k == s.length() || s[k] > '9' || s[k] < '0') return false;
        }
        while (k < s.length() && s[k] >= '0' && s[k] <= '9') k++;

        //after all
        while (k < s.length())
            if (s[k++] != ' ') return false;
        return true;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);
    cout << sol.isNumber(s) << endl;

    return 0;
}
