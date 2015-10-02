/* LC ID :  #13
 * Type  :  String Processing
 * Author:  Hangchen Yu
 * Date  :  04/18/2015
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
    int val(char x) {
        switch (x) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
    }

    int romanToInt(string s) {
        int i = 0, sum = 0;
        while (i < s.length()) {
            if (i < s.length()-1 && val(s[i]) < val(s[i+1])) {
                sum += val(s[i+1]) - val(s[i]);
                i += 2;
            }
            else {
                sum += val(s[i]);
                i++;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.romanToInt(s) << endl;

    return 0;
}
