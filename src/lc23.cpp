/* LC ID :  #23
 * Type  :  Heap, sort
 * Author:  Hangchen Yu
 * Date  :  04/12/2015
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

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
    struct MyComparator {
        bool operator() (ListNode* a, ListNode* b) {
            return (a->val > b->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyComparator> heap; 
        for (int i = 0; i < lists.size(); i++)
            if (lists[i]) heap.push(lists[i]);
        if (heap.empty()) return NULL;

        ListNode *head = NULL, *link, *t;
        while (!heap.empty()) {
            t = heap.top();
            if (!head)
                head = link = t;
            else {
                link->next = t;
                link = t;
            }
            heap.pop();
            t = t->next;
            if (t) heap.push(t);
        }

        return head;        
    }
};

int main() {
    Solution sol;
    ListNode *t1 = new ListNode(12), *h1 = t1;
    t1->next = new ListNode(15); t1 = t1->next;
    t1->next = new ListNode(18); t1 = t1->next;
    t1->next = new ListNode(19); t1 = t1->next;
    t1->next = new ListNode(23); t1 = t1->next;
    t1->next = new ListNode(27); t1 = t1->next;
    t1->next = new ListNode(29);

    ListNode *t2 = new ListNode(1), *h2 = t2;
    t2->next = new ListNode(13); t2 = t2->next;
    t2->next = new ListNode(14); t2 = t2->next;
    t2->next = new ListNode(15); t2 = t2->next;
    t2->next = new ListNode(16); t2 = t2->next;
    t2->next = new ListNode(20); t2 = t2->next;
    t2->next = new ListNode(31);

    ListNode *h3 = NULL;

    ListNode *t4 = new ListNode(2), *h4 = t4;
    t4->next = new ListNode(3); t4 = t4->next;
    t4->next = new ListNode(4); t4 = t4->next;
    t4->next = new ListNode(10); t4 = t4->next;
    t4->next = new ListNode(19); t4 = t4->next;
    t4->next = new ListNode(35);

    vector<ListNode*> tt;
    tt.push_back(h1); tt.push_back(h2); tt.push_back(h3); tt.push_back(h4);
    ListNode *h = sol.mergeKLists(tt);    
    
    while (h) {
        printf("%d ", h->val);
        h = h->next;
    }
    cout << endl;
    return 0;
}
