/* LC ID :  #31
 * Type  :  Sort
 * Author:  Hangchen Yu
 * Date  :  06/27/2015
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
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k] <= nums[--k]);

        int head = nums[k];
        sort(nums.begin()+k, nums.end());
        for (int i = k; i < nums.size() - 1; i++)
            if (nums[i] == head && nums[i+1] != head) {
                for (int j = i; j >= k; j--)
                    swap(nums[j], nums[j+1]);
                break;
            }
    }
};

int main() {
    Solution sol;
    int n, x;
	cin >> n;
	vector<int> s;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.push_back(x);
	}
	sol.nextPermutation(s);

	for (int i = 0; i < n; i++) {
		cout << s[i];
		if (i == n-1) cout << endl;
		else cout << " ";
	}

    return 0;
}
