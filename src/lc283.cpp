/* LC ID :  #283
 * Type  :  Array
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

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//copy the Solution class here
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        while (k < nums.size() && nums[k]) k++;
        for (int i = k+1; i < nums.size(); i++) {
            if (!nums[i]) continue;
            swap(nums[i], nums[k]);
            k++;
        }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
