/* LC ID :  #21
 * Type  :  
 * Author:  Hangchen Yu
 * Date  :  04/28/2015
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = NULL;
        ListNode* head = NULL;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (!l)
                    head = l = l1;
                else {
                    l->next = l1;
                    l = l1;
                }
                l1 = l1->next;                
            }
            else {
                if (!l)
                    head = l = l2;
                else {
                    l->next = l2;
                    l = l2;
                }
                l2 = l2->next;
            }
        }

        if (!l1) l1 = l2;
        if (!head) head = l1;
        else {
            while (l1) {
                l->next = l1;
                l = l1;
                l1 = l1->next;
            }
        }

        return head;
        
    }
};

int main() {
    Solution sol;
    ListNode* a, * b, * ah=NULL, * bh=NULL;
    int n, m, x;
    cin >> n >> m;
    if (n > 0) { cin >> x; ah = a = new ListNode(x); }
    for (int i = 1; i < n; i++) {
        cin >> x;
        a->next = new ListNode(x);
        a = a->next;
    }
    if (m > 0) { cin >> x; bh = b = new ListNode(x); }
    for (int i = 1; i < m; i++) {
        cin >> x;
        b->next = new ListNode(x);
        b = b->next;
    }   
    ListNode* t = sol.mergeTwoLists(ah, bh);    
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
