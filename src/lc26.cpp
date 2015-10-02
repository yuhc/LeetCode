/* LC ID :  #26
 * Type  :  Sort
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int count = 0;
        nums.push_back(nums[nums.size()-1]+1);
        
        for (int i = 0; i < nums.size()-1; i++)
            if (nums[i] != nums[i+1])
                count++;
            else {
                nums.erase(nums.begin()+i);
                i--;
            }
        nums.erase(nums.end()-1);
        return count;
    }
};

int main() {
    Solution sol;
    int n, x;
    vector<int> nu;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nu.push_back(x);
    }
    cout << sol.removeDuplicates(nu) << endl;    

    for (int i = 0; i < nu.size(); i++)
        cout << nu[i] << " ";
    cout << endl;

    return 0;
}
