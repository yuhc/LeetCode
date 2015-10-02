/* LC ID :  #82
 * Type  :  Link
 * Author:  Hangchen Yu
 * Date  :  09/15/2015
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *t = head, *last = start;

        while (t) {
            bool dup = false;
            int val = t->val;
            if (t && t->next && t->val == t->next->val)
                dup = true;
            if (dup) {
                while (t->next && t->next->val == val) t = t->next;
                last->next = t->next;
                t = t->next;
            }
            else {
                last = t;
                if (t) t = t->next;
            }
        }

        return start->next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* t = new ListNode(1);
    head->next = t;
    t->next = new ListNode(2); t = t->next;
    t->next = new ListNode(2); t = t->next;
    t->next = new ListNode(2); t = t->next;
    t->next = new ListNode(3); t = t->next;


    t = sol.deleteDuplicates(head);
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
