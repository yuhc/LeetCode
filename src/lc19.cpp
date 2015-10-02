/* LC ID :  #19
 * Type  :  Linked List
 * Author:  Hangchen Yu
 * Date  :  04/27/2015
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

using namespace std;

//copy the Solution class here
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int dfs(ListNode* pre, ListNode* &now, int n) {
        if (!now) return 0;
        int k = dfs(now, now->next, n) + 1;
        if (k == n) {
            if (pre) {
                pre->next = now->next;
                //delete now;
            }
            else {
                //ListNode* t = now;
                now = now->next;
                //delete t;
            }
        }
        return k;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        dfs(NULL, head, n);
        return head;
    }
};

int main() {
    Solution sol;
    int k, x; cin >> k >> x;
    ListNode* head = new ListNode(x), *t = head;
    for (int i = 0; i < k-1; i++) {
        cin >> x;
        t->next = new ListNode(x); t = t->next;
    }
    //t->next = new ListNode(4); t = t->next;
    //t->next = new ListNode(5); t = t->next;
    //t->next = new ListNode(6); t = t->next;
    int n; cin >> n;
    head = sol.removeNthFromEnd(head, n);
    t = head;
    while (t != NULL) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
    return 0;
}
