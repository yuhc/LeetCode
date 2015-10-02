/* LC ID :  #278
 * Type  :  Binary Search
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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int left = 1, right = n;
        unsigned int mid = (left+right) >> 1;
        int ans = n;
        
        while (left <= right) {
            if (isBadVersion(mid)) {
                if (mid < ans) ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
            mid = (left+right) >> 1;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
