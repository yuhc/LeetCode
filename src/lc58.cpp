/* LC ID :  #58
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/09/2015
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
    int lengthOfLastWord(string s) {
        int ans = 0;
        int k = s.length()-1;
        while (k >= 0 && s[k] == ' ') k--;
        if (k < 0) return 0;

        while (k >= 0 && s[k] != ' ') {
            ans++; k--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);
    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}
