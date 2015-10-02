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

        ListNode *now = head, *last = NULL;
        int len = 0;
        while (now) {
            if (!now->next) last = now;
            now = now->next;
            len++;
        }
        //if (k >= len) return head;
        k %= len;

        ListNode *pre = head;
        for (int i = 1; i < len-k; i++)
            pre = pre->next;
        last->next = head;
        head = pre->next;
        pre->next = NULL;
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
