/* LC ID :  #166
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/13/2015
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
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";

        bool neg = ((numerator<0||denominator<0)&&!(numerator<0&&denominator<0));
        double numerat, denominat;
        if (numerator < 0) numerat = -double(numerator); else numerat = numerator;
        if (denominator < 0) denominat = -double(denominator); else denominat = denominator;

        string s = (neg?"-":"") + to_string((unsigned int)(numerat/denominat));

        //integer
        if (numerat >= denominat && (unsigned int)(numerat-(unsigned int)(numerat/denominat)*denominat) == 0)
            return s;

        //float
        s += '.';
        double  remainder[1000];
        int quotient[1000];
        int len = 0;
        remainder[0] = (unsigned int)numerat%(unsigned int)denominat;
        bool loop = false;
        int  loopstart;
        while (!loop) {
            quotient[++len] = remainder[len-1]*10/denominat;
            remainder[len] = (remainder[len-1]*10)-(unsigned int)(remainder[len-1]*10/denominat)*denominat;
            if (remainder[len] == 0) break;

            for (int i = 1; i < len; i++)
                if (quotient[i] == quotient[len] && remainder[i] == remainder[len]) {
                    loop = true;
                    loopstart = i;
                    break;
                }
        }

        //not loop
        if (!loop) {
            for (int i = 1; i <= len; i++)
                s += to_string(quotient[i]);
            return s;
        }

        //loop
        for (int i = 1; i < loopstart; i++)
            s += to_string(quotient[i]);
        s += '(';
        for (int i = loopstart; i < len; i++)
            s += to_string(quotient[i]);
        s += ')';
        return s;
    }
};

int main() {
    Solution sol;
    int x, y;
    cin >> x >> y;
    cout << sol.fractionToDecimal(x, y) << endl;

    return 0;
}
