/* LC ID :  #61
 * Type  :  Link
 * Author:  Hangchen Yu
 * Date  :  09/10/2015
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

//definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//copy the Solution class here
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *now = head;
        ListNode *l = NULL, *r = NULL, *oldr;

        for (int i = 0; i <= k; i++) {
            if (i == k) oldr = now;
            if (now->next) now = now->next;
            else return head;
        }

        while (now) {
            l = r = now;
            for (int i = 0; i < k; i++) {
                if (!now->next) { r = now; break; }
                now = now->next;
                r = now;
            }

            now = now->next;
            oldr->next = r->next;
            r->next = head;
            head = l;

            if (!now) return head;
        }

        return head;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    ListNode *head = new ListNode(1);
    ListNode *now = head;
    for (int i = 2; i <= n; i++) {
        ListNode *t = new ListNode(i);
        now->next = t;
        now = t;
    }
    ListNode *ans = sol.rotateRight(head, k);

    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}
