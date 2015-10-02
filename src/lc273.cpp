/* LC ID :  #273
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  08/31/2015
 */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//copy the Solution class here
class Solution {
public:
    string numberToWords(int num) {
        const string wordlist[31] = {"Zero",
                                     "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "",
                                     "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const string level[4] = {"", "Thousand", "Million", "Billion"};

        if (!num) return wordlist[0];

        string s[10];
        for (int i = 0; i < 10; i++) s[i] = "";
        int l = 0;
        while (num > 0) {
            int t = num % 1000;
            if (!t) {
                num /= 1000; l++; continue;
            }
            if (t > 99) s[l*3+2] += wordlist[t/100] + " Hundred";
            if ((t%=100) > 9)
                s[l*3+1] = (t >= 20)?wordlist[t/10+19]+((t%10)?" "+wordlist[t%10]:""):wordlist[t];
            else
                s[l*3] = (t)?wordlist[t]:"";
            if (num % 1000 && l > 0) s[l*3] += (s[l*3].empty()?"":" ") + level[l];
            num /= 1000;
            l++;
        }

        string ans = "";
        for (int i = 9; i >= 0; i--)
            if (s[i] != "") ans += s[i] + " ";
        if (ans[ans.length()-1] == ' ') return ans.substr(0, ans.length()-1);
        else return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.numberToWords(n) << "*" << endl;

    return 0;
}
