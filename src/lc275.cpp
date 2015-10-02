/* LC ID :  #275
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

//copy the Solution class here
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n) return 0;
        
        int left = 0, right = n-1;
        int mid = (left+right) >> 1;
        int h = 0;
        while (left <= right) {
            if (citations[mid] >= n-mid) {
                h = max(h, n-mid);
                right = mid-1;
            }
            else
                left = mid+1;
            mid = (left+right) >> 1;
        }
        
        return h;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
