/* LC ID :  #92
 * Type  :  Link
 * Author:  Hangchen Yu
 * Date  :  09/16/2015
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = 0;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *t = start;
        while (t) {
            len++;
            t = t->next;
        }

        ListNode *last = start;
        for (int i = 0; i < m-1; i++) last = last->next;
        ListNode *nxt = last->next;
        for (int i = 1; i < n-m+1; i++) {
            t = nxt->next;
            nxt->next = t->next;
            t->next = last->next;
            last->next = t;
        }

        return start->next;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
