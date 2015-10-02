/* LC ID :  #201
 * Type  :  Bit Manipulation
 * Author:  Hangchen Yu
 * Date  :  09/28/2015
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
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        
        while (m > 0) {
            int len = 0, t = n;
            while (t > 0) {
                len++;
                t >>= 1;
            }
        
            if ((m & (1<<(len-1))) == 0) break;
            else {
                ans |= 1<<(len-1);
                m ^= 1<<(len-1);
                n ^= 1<<(len-1);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
