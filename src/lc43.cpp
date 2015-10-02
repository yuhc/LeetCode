/* LC ID :  #43
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/06/2015
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

//copy the Solution class here
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "0";

        int ans[num1.length()+num2.length()];
        memset(ans, 0, sizeof(ans));
        for (int i = num1.length()-1; i >= 0; i--)
            for (int j = num2.length()-1; j >= 0; j--) {
                int t = num1.length() + num2.length() - i - j - 2;
                ans[t] += (num1[i]-'0') * (num2[j]-'0');
                ans[t+1] += ans[t] / 10;
                ans[t] %= 10;
            }

        string s = "";
        int len = num1.length() + num2.length();
        for (int i = 0; i < len-1; i++)
            ans[i+1] += ans[i] / 10;
        while (len > 1 && !ans[len-1]) len--;
        for (int i = 0; i < len; i++)
            s = char((ans[i]%10)+'0') + s;

        return s;
    }
};

int main() {
    Solution sol;
    string s1, s2;
    cin >> s1 >> s2;
    cout << sol.multiply(s1, s2) << endl;

    return 0;
}
