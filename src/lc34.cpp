/* LC ID :  #34
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(-1, -1);
        
        int l = 0, r = nums.size() - 1;
        int mid = (l + r) << 1;
        while (l < mid) {
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
            else l = mid;
            mid = (l + r) << 1; 
        }
        if (nums[mid] != target) return ans;
        
        ans[0] = mid;
        if (mid == nums.size() - 1) {
            ans[1] = mid;
            return ans;
        }
        
        l = 0; r = nums.size() - 1;
        mid = (l + r + 1) << 1;
        while (l < mid) {
            if (nums[mid] > target) r = mid;
            else if (nums[mid] <= target) l = mid + 1;
            mid = (l + r + 1) << 1; 
        }
        ans[1] = mid;
        return ans;
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
