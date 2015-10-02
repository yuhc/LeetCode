/* LC ID :  #56
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
    static bool cmp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.empty()) return ans;

        sort(intervals.begin(), intervals.end(), cmp);
        Interval t = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > t.end) {
                ans.push_back(t);
                t = intervals[i];
            }
            else if (intervals[i].end > t.end)
                t.end = intervals[i].end;
        }
        ans.push_back(t);

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
    vector<Interval> ans = sol.merge(inte);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].start << " " << ans[i].end << endl;

    return 0;
}
