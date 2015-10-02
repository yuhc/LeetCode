/* LC ID :  #57
 * Type  :  Sort
 * Author:  Hangchen Yu
 * Date  :  09/09/2015
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

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//copy the Solution class here
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int k = 0;
        while (k < intervals.size() && intervals[k].end < newInterval.start) {
            ans.push_back(intervals[k]);
            k++;
        }
        ans.push_back(newInterval);
        if (k == intervals.size())
            return ans;

        int m = k;
        //in front of newInterval
        if (newInterval.start >= intervals[k].start) {
            ans[k].start = intervals[k].start;
            if (intervals[k].end > ans[k].end) ans[k].end = intervals[k].end;
            k++;
        }

        //in newInterval
        while (k < intervals.size() && intervals[k].end <= ans[m].end) { k++; };
        if (k == intervals.size()) return ans;

//        cout << ans[m].start << " " << ans[m].end << endl;
//        cout << intervals[k].start << " " << intervals[k].end << endl;
        //behind newInterval
        if (intervals[k].start <= ans[m].end) {
            ans[m].end = intervals[k].end;
            k++;
        }

        while (k < intervals.size())
            ans.push_back(intervals[k++]);

        return ans;
    }
};

int main() {
    Solution sol;
    int n, a, b;
    cin >> n;
    vector<Interval> inte;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        Interval t(a, b);
        inte.push_back(t);
    }
    cin >> a >> b;
    vector<Interval> ans = sol.insert(inte, Interval(a, b));
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].start << " " << ans[i].end << endl;

    return 0;
}
