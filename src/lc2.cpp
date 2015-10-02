/* LC ID :  #2
 * Type  :  Linked List
 * Author:  Hangchen Yu
 * Date  :  04/13/2015
 */
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

using std::swap;
using std::vector;
using std::pair;

//copy the Solution class here

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *c = ans;
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        int t;
        while (h1 != NULL && h2 != NULL) {
            t = c->val + h1->val + h2->val;
            c->val = t%10;
            c->next = new ListNode(t/10);
            c = c->next;
            h1 = h1->next;
            h2 = h2->next;
        }

        ListNode *h;
        if (h1 == NULL) h = h2;
        else h = h1;
        while (h != NULL) {
            t = c->val + h->val;
            c->val = t%10;
            c->next = new ListNode(t/10);
            h = h->next;
            c = c->next;
        }

        if (c->val == 0) {
            ListNode *p = ans;
            while (p->next != c) p = p->next;
            p->next = NULL;
        }

        return ans;
    }
};

int main() {
    Solution s;
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    ListNode *t1 = l1;
    l1->next = new ListNode(4); l1 = l1->next;
    l1->next = new ListNode(3); l1 = l1->next;
    l2 = new ListNode(5);
    ListNode *t2 = l2;
    l2->next = new ListNode(6); l2 = l2->next;
    l2->next = new ListNode(6); l2 = l2->next;
    l2->next = new ListNode(9); l2 = l2->next;
    
    ListNode *v = s.addTwoNumbers(t1, t2);
    while (v != NULL) {
        printf("%d ", v->val);
        v = v->next;
    }
    return 0;
}
