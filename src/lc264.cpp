/* LC ID :  #264
 * Type  :  Heap
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
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
    static bool cmp(const unsigned int &a, const unsigned int &b) {
        return (a>b);
    }

    int nthUglyNumber(int n) {
        vector<unsigned int> heap;
        heap.push_back(1);
        make_heap(heap.begin(), heap.end(), cmp);

        const unsigned int MAXINT = ((1<<(sizeof(unsigned int)*8-1))-1)*2+1;
        for (int k = 0; k < n-1; k++) {
            unsigned int t = heap.front();
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            while (!heap.empty() && heap.front() == t) {
                pop_heap(heap.begin(), heap.end(), cmp);
                heap.pop_back();
            }
            if (t <= MAXINT/2) {
                heap.push_back(t*2); push_heap(heap.begin(), heap.end(), cmp);
            }
            if (t <= MAXINT/3) {
                heap.push_back(t*3); push_heap(heap.begin(), heap.end(), cmp);
            }
            if (t < MAXINT/5) {
                heap.push_back(t*5); push_heap(heap.begin(), heap.end(), cmp);
            }
        }

        return heap.front();
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.nthUglyNumber(n) << endl;

    return 0;
}
