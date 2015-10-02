/* LC ID :  #15
 * Type  :  Array, Sort
 * Author:  Hangchen Yu
 * Date  :  04/24/2015
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

// copy the Solution class here
// for a+b+c=0, given a, we only need to find b+c=-a, which is a 2sum problem
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > triplet;
        vector<int> tmp(3);
        sort(num.begin(), num.end());

        for (int a = 0; a < int(num.size())-2;) {
            int b = a+1, c = num.size()-1;
            while (b < c) {
                if (num[b] + num[c] < -num[a])
                    while (num[b] == num[++b] && b < c);
                else if (num[b] + num[c] > -num[a])
                    while (num[c] == num[--c] && b < c);
                else {
                    tmp[0] = num[a];
                    tmp[1] = num[b];
                    tmp[2] = num[c];
                    triplet.push_back(tmp);
                    while (num[b] == num[++b] && b < c);
                    while (num[c] == num[--c] && b < c);
                }
            }
            while (num[a] == num[++a] && a < int(num.size())-2);
        }

        return triplet;
    }
};

int main() {
    Solution sol;
    vector<int> num;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        num.push_back(x);
    }
    vector<vector<int> > t;
    t = sol.threeSum(num);
    for (int i = 0; i < t.size(); i++) {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }

    return 0;
}
