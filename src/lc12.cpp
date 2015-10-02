/* LC ID :  #12
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
    string intToRoman(int num) {
        string s = "";
        //M
        while (num >= 1000) {
            num -= 1000;
            s += 'M';
        }
        //CM
        if (num >= 900) {
            num -= 900;
            s += "CM";
        }

        //DC
        if (num >= 500) {
            s += 'D';
            for (int i = 0; i < (num/100-5); i++)
                s += 'C';
            num %= 100;
        }

        //CD
        if (num >= 400) {
            s += "CD";
            num -= 400;
        }

        //C
        while (num >= 100) {
            s += 'C';
            num -= 100;
        }

        //XC
        if (num >= 90) {
            num -= 90;
            s += "XC";
        }

        //LX
        if (num >= 50) {
            s += 'L';
            for (int i = 0; i < (num/10-5); i++)
                s += 'X';
            num %= 10;
        }

        //XL
        if (num >= 40) {
            s += "XL";
            num -= 40;
        }

        //X
        while (num >= 10) {
            s += 'X';
            num -= 10;
        }

        //IX
        if (num == 9)
            s += "IX";
        else if (num >= 5) {
            s += 'V';
            for (int i = 0; i < num-5; i++)
                s += 'I';
        }
        else if (num == 4)
            s += "IV";
        else
            for (int i = 0; i < num; i++)
                s += 'I';

        return s;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.intToRoman(n) << endl;

    return 0;
}
