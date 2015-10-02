/* LC ID :  #8
 * Type  :  String Processing
 * Author:  Hangchen Yu
 * Date  :  04/18/2015
 */
#include <cstdio>
#include <iostream>
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
    int myAtoi(string str) {
        if (str.empty()) return 0;
        
        long i = 0;
        while (i < str.length() && isspace(str[i])) {
            i++;
        }

        // + and -
        if (i >= str.length() || !(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
            return 0;
        long sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') i++;

        // transform
        if (i >= str.length() || !(str[i] >= '0' && str[i] <= '9'))
            return 0;
        long t = 0;
        while (i < str.length() && str[i] == '0') i++;  // -0 is storaged as positive 0
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            t *= 10;
            t += sign * (str[i]-'0');
            if ((t&(1<<31))^(sign&(1<<31))) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            i++;
        }
        return t;
    }
};

int main() {
    Solution s;
    string str;
    getline(cin, str);
    cout << s.myAtoi(str) << endl;
    return 0;
}
