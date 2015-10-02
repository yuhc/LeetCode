/* LC ID :  #42
 * Type  :  Stack
 * Author:  Hangchen Yu
 * Date  :  09/06/2015
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

//copy the Solution class here
class Solution {
private:
    struct HeightDist {
        int h, dis;
        HeightDist(int a, int b) {
            h = a; dis = b;
        }
    };

public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        stack<HeightDist> s;
        HeightDist now(height[0], 0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < now.h) {
                s.push(now);
                now.h = height[i];
                now.dis = i;
            }
            else if (height[i] > now.h) {
                while (!s.empty() && (s.top()).h <= height[i]) {
                    HeightDist tmp = s.top();
                    s.pop();
                    sum += (tmp.h-now.h) * (i-now.dis);
                    now = tmp;
                }
                if (!s.empty() && (s.top().h > height[i])) {
                    sum += (height[i]-now.h) * (i-now.dis);
                    now.h = height[i];
                }
                if (s.empty()) {
                    now.h = height[i];
                    now.dis = i;
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    int n, x; vector<int> h;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; h.push_back(x);
    }
    cout << sol.trap(h) << endl;

    return 0;
}
