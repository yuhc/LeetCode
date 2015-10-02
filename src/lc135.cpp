/* LC ID :  #135
 * Type  :  Greedy
 * Author:  Hangchen Yu
 * Date  :  09/14/2015
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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int f[n];
        fill_n(f, n, 1);

        //left to right
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1]) f[i] = f[i-1]+1;
        //right to left
        for (int i = n-1; i > 0; i--)
            if (ratings[i] < ratings[i-1]) f[i-1] = max(f[i-1], f[i]+1);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += f[i];
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1,2,1,3,2,4,3};
    cout << sol.candy(ratings) << endl;

    return 0;
}
