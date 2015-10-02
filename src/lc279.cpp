/* LC ID :  #279
 * Type  :  Dynamic Programming
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
    int numSquares(int n) {
        int dp[n+1];
        fill_n(dp, n+1, n+1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i-j*j]+1, dp[i]);
        return dp[n];
    }
};

int main() {
    Solution sol;
    

    return 0;
}
