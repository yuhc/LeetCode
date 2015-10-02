/* LC ID :  #86
 * Type  :  List
 * Author:  Hangchen Yu
 * Date  :  09/14/2015
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *t = start, *last = start;

        while (1) {
            while (last->next && last->next->val < x) last = last->next;
            if (!last->next) break;
            t = last;
            while (t->next && t->next->val >= x) t = t->next;
            if (!t->next) break;
            ListNode *tmp = t->next->next;
            t->next->next = last->next;
            last->next = t->next;
            t->next = tmp;
        }

        return start->next;
    }

};

int main() {
    Solution sol;
    

    return 0;
}
