/* LC ID :  #33
 * Type  :  Binary Search
 * Author:  Hangchen Yu
 * Date  :  07/02/2015
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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = (l + r) >> 1;
        while (l <= r) {
            if (nums[mid] == target) return mid;
            if ((nums[mid] >= nums[l] && (target > nums[mid] || target < nums[l]))
             || (nums[mid] <= nums[l] && target > nums[mid] && target <= nums[r]))
                l = mid + 1;
            else
                r = mid - 1;
            mid = (l + r) >> 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    int n, x;
	cin >> n;
	vector<int> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		m.push_back(x);
	}
	cin >> n;
	cout << sol.search(m, n) << endl;

    return 0;
}
