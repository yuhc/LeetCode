/* LC ID :  #287
 * Type  :  Bit Manipulation
 * Author:  Hangchen Yu
 * Date  :  09/29/2015
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

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//copy the Solution class here
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int bit_num[32], bit_all[32];
        memset(bit_num, 0, sizeof(bit_num));
        memset(bit_all, 0, sizeof(bit_all));
        
        for (int i = 0; i < nums.size(); i++)
            for (int k = 0; k < 32; k++)
                if (nums[i]&(1<<k)) bit_num[k]++;
        for (int i = 1; i < n; i++)
            for (int k = 0; k < 32; k++)
                if (i&(1<<k)) bit_all[k]++;
        
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (bit_num[i] > bit_all[i]) ans |= 1<<i;
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
