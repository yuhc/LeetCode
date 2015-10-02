/* LC ID :  #240
 * Type  :  Array
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (!n) return false;
        int m = matrix[0].size();
        int i = 0, j = m-1;
        
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
