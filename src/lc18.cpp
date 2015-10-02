/* LC ID :  #18
 * Type  :  Array, Sort
 * Author:  Hangchen Yu
 * Date  :  04/26/2015
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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        if (num.size() < 4) return ans;

        vector<int> tmp(4);
        sort(num.begin(), num.end());

        for (int a = 0; a < num.size() - 3;) {
            for (int b = a + 1; b < num.size() - 2;) {
                int c = b + 1, d = num.size() - 1;
                while (c < d) {
                    int sum = num[a] + num[b] + num[c] + num[d];
                    if (sum < target)
                        while (num[c] == num[++c] && c < d);
                    else if (sum > target)
                        while (num[d] == num[--d] && c < d);
                    else {
                        tmp[0] = num[a];
                        tmp[1] = num[b];
                        tmp[2] = num[c];
                        tmp[3] = num[d];
                        ans.push_back(tmp);
                        while (num[c] == num[++c] && c < d);
                        while (num[d] == num[--d] && c < d);
                    }
                }
                while (num[b] == num[++b] && b < num.size()-2);
            }
            while (num[a] == num[++a] && a < num.size()-3);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    int x;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.push_back(x);
    }
    vector<vector<int> > ans = sol.fourSum(t, k);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
