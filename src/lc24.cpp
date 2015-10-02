/* LC ID :  #1
 * Type  :  
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *nx, *nxnx, *pre, *now;
        //head
        nx = head->next;
        nxnx = nx->next;
        head->next = nxnx;
        nx->next = head;
        pre = head;
        head = nx;
        now = nxnx;

        //inner
        while (now) {
            if (!now->next) break;
            nx = now->next;
            nxnx = nx->next;
            nx->next = now;
            now->next = nxnx;
            pre->next = nx;
            pre = now;
            now = nxnx;
        }

        return head;        
    }
};

int main() {
    Solution sol;
    int n, x;
    ListNode *t = new ListNode(1), *h = t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t->next = new ListNode(x);
        t = t->next;
    }

    t = sol.swapPairs(h->next);
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
