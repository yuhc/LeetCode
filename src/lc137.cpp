/* LC ID :  #137
 * Type  :  Bit
 * Author:  Hangchen Yu
 * Date  :  09/22/2015
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
#include <climits>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL),
    next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /**
         * current input output
         *   ab      c     ab
         *   00      0     00
         *   01      0     01
         *   10      0     10
         *   00      1     01
         *   01      1     10
         *   10      1     00
         * except one which ab == 01 or 10
         * return a|b
         */
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t;
            t = (a&(~b)&(~nums[i]))|((~a)&b&nums[i]);
            b = ((~a)&b&(~nums[i]))|((~a)&(~b)&nums[i]);
            a = t;
        }
        return a|b;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
