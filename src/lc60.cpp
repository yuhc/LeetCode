/* LC ID :  #60
 * Type  :  Math
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
    string getPermutation(int n, int k) {
        k--;
        int p = 1;
        for (int i = 1; i < n; i++) p *= i;
        int order[10];
        for (int i = n-1; i >= 0; i--) {
            order[i] = k/p;
            k %= p;
            if (i) p /= i;
        }

        bool bj[10];
        memset(bj, false, sizeof(bj));
        string ans = "";
        for (int i = n-1; i >= 0; i--) {
            int t = 0;
            for (int j = 1; j <= n; j++)
                if (!bj[j]) {
                    if (t == order[i]) {
                        ans += j+'0';
                        bj[j] = true;
                        break;
                    }
                    t++;
                }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int k, n;
    cin >> n >> k;
    cout << sol.getPermutation(n, k) << endl;

    return 0;
}
