/* LC ID :  #27
 * Type  :  Array
 * Author:  Hangchen Yu
 * Date  :  05/08/2015
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
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size()-1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) continue;
            while (i < r && nums[i] == val) {
                swap(nums[i], nums[r]);
                r--;
            }
            if (i >= r) break;
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val) count++;
            else break;
        return count;        
    }
};

int main() {
    Solution sol;
    int n, x, val;
    vector<int> nu;
    cin >> n >> val;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nu.push_back(x);
    }
    cout << sol.removeElement(nu, val) << endl;    

    for (int i = 0; i < nu.size(); i++)
        cout << nu[i] << " ";
    cout << endl;

    return 0;
}
