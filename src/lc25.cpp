/* LC ID :  #25
 * Type  :  Linked List
 * Author:  Hangchen Yu
 * Date  :  05/08/2015
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        
        ListNode *section, *next_section, *now, *pre, *t;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        section = new_head;
        
        int count;
        while (1) {
            count = 0;
            now = section;
            while (now->next && count < k) {
                count++;
                now = now->next;
            }
            if (count < k) return new_head->next;
            next_section = section->next;
            
            now = pre = section->next;
            for (int i = 0; i < k-1; i++) {
                now = now->next;
                t = section->next;
                section->next = now;
                pre->next = now->next;
                now->next = t;
                now = pre;            
            }

            section = next_section;
        }
    }
};

int main() {
    Solution sol;
    int n, x, k;
    ListNode *t = new ListNode(1), *h = t;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        t->next = new ListNode(i+1);
        t = t->next;
    }

    t = sol.reverseKGroup(h->next, k);
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
    

    return 0;
}
