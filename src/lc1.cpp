/* LC ID :  #1
 * Type  :  Sort
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
 */
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

using std::swap;
using std::vector;
using std::pair;

class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        pair<int, int> p;
        vector<pair<int, int> > num;
        for (int i = 0; i < numbers.size(); i++) {
            p.first = numbers[i];
            p.second = i;
            num.push_back(p);
        }
        sort(num.begin(), num.end(), this->cmp);

        int i = 0, j = numbers.size()-1;
        while (i < j) {
            while (j > i && num[i].first + num[j].first > target) j--;
            if (num[i].first + num[j].first == target) {
                vector<int> tmp;
                tmp.push_back(num[i].second+1);
                tmp.push_back(num[j].second+1);
                if (num[i].second > num[j].second) swap(tmp[0], tmp[1]);
                return tmp;
            }
            i++;
        }
    }
};

int main() {
    Solution s;
    vector<int> num;
    num.push_back(7);
    num.push_back(2);
    num.push_back(11);
    num.push_back(5);
    num.push_back(3);
    num.push_back(15);
    num.push_back(8);
    vector<int> v = s.twoSum(num, 9);
    printf("%d %d\n", v[0], v[1]);
    return 0;
}
