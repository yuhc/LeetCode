/* LC ID :  #118
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row;
        if (!numRows) return ans;

        row.push_back(1);
        ans.push_back(row);
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < i; j++)
                row[j] = ans[i-1][j] + ans[i-1][j-1];
            row.push_back(1);
            ans.push_back(row);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
