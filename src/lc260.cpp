/* LC ID :  #260
 * Type  :  Bit Manipulation
 * Author:  Hangchen Yu
 * Date  :  09/30/2015
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
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xor_all = 0;
        for (int i = 0; i < nums.size(); i++) xor_all ^= nums[i];
        
        int t = 1;
        int xor_single = 0;
        while ((xor_all&t) != t) t <<= 1;
        for (int i = 0; i < nums.size(); i++)
            if ((nums[i]&t) == t) xor_single ^= nums[i];
        ans.push_back(xor_single);
        ans.push_back(xor_single^xor_all);
        
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
