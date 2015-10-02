/* LC ID :  #66
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/11/2015
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
    vector<int> plusOne(vector<int>& digits) {
        int firstnonzero = 0;
        while (firstnonzero < digits.size() && digits[firstnonzero] == 0) firstnonzero++;
        if (firstnonzero == digits.size()) return vector<int>(1, 1);
        bool allnine = true;
        for (int i = firstnonzero; i < digits.size(); i++)
            if (digits[i] != 9) {
                allnine = false;
                break;
            }

        vector<int> ans;
        if (allnine) {
            ans.push_back(1);
            for (int i = firstnonzero; i < digits.size(); i++)
                ans.push_back(0);
        }
        else {
            for (int i = firstnonzero; i < digits.size(); i++)
                ans.push_back(digits[i]);
            int len = ans.size();
            ans[len-1]++;
            for (int i = len-1; i > 0; i--)
                if (ans[i] > 9) {
                    ans[i-1]++;
                    ans[i] %= 10;
                }
                else break;
        }

        return ans;
    }

};

int main() {
    Solution sol;
    int n, x;
    cin >> n;
    vector<int> dig;
    for (int i = 0; i < n; i++) {
        cin >> x; dig.push_back(x);
    }
    vector<int> ans = sol.plusOne(dig);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;

    return 0;
}
