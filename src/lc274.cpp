/* LC ID :  #274
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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count[n+1];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; i++) {
            int t = citations[i]>n?n:citations[i];
            count[t]++;
        }
        
        int h = min(count[n], n);
        for (int i = n-1; i >= 1; i--) {
            count[i] += count[i+1];
            h = max(h, min(count[i], i));
        }
        
        return h;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
