/* LC ID :  #109
 * Type  :  Tree + Link
 * Author:  Hangchen Yu
 * Date  :  09/19/2015
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        ListNode *tail = head;
        int count = 1;
        while (tail->next) {
            count++;
            tail = tail->next;
        }
        TreeNode *root = new TreeNode(0);
        dfs(root, head, tail, count);
        return root;
    }

    void dfs(TreeNode *t, ListNode *head, ListNode *tail, int count) {
        ListNode *mid = head, *pre;
        for (int i = 0; i < count/2; i++) {
            pre = mid;
            mid = mid->next;
        }
        t->val = mid->val;

        if (head != mid) {
            t->left = new TreeNode(0);
            dfs(t->left, head, pre, count/2);
        }
        if (mid != tail) {
            t->right = new TreeNode(0);
            dfs(t->right, mid->next, tail, count-count/2-1);
        }
    }
};

int main() {
    Solution sol;
    

    return 0;
}
