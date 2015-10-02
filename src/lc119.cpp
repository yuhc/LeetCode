/* LC ID :  #119
 * Type  :  Math
 * Author:  Hangchen Yu
 * Date  :  09/20/2015
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

//copy the Solution class here
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, row;
        row.push_back(1);
        ans.push_back(1);
        if (!rowIndex) return row;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++)
                row[j] = ans[j] + ans[j-1];
            row.push_back(1);
            ans = row;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
