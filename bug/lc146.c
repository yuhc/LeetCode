/* LC ID :  #8
 * Type  :  
 * Author:  Hangchen Yu
 * Date  :  09/15/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
struct node {
    int key;
    int val;
    struct node *pre, *next;
};

struct node *head;

void printCache() {
    struct node *h = head->next;
    while (h) {
        printf("(%d,%d)->", h->key, h->val);
        h = h->next;
    }
    printf("END\n");
}

void lruCacheInit(int capacity) {
    head = (struct node *)malloc(sizeof(struct node));
    head->pre = NULL;
    struct node *h = head;
    for (int i = 0; i < capacity; ++i) {
        h->next = (struct node *)malloc(sizeof(struct node));
        h->next->pre = h;
        h = h->next;
        h->key = h->val = -1;
    }
    h->next = NULL;
}

void lruCacheFree() {
    struct node *h = head;
    while (h) {
        head = h->next;
        free(h);
        h = head;
    }
}

int lruCacheGet(int key) {
    struct node *h = head->next;
    // TODO: add a hashtable for the keys
    while (h) {
        if (h->key == key && h->val > 0) {
            if (h->pre != head) {
                h->pre->next = h->next;
                if (h->next) h->next->pre = h->pre;
                h->next = head->next;
                head->next->pre = h;
                head->next = h;
                h->pre = head;
            }
            return h->val;
        }
        h = h->next;
    }

    return -1;
}

void lruCacheSet(int key, int value) {
    struct node *h = head->next;
    while (h) {
        if (h->key == key && h->val > 0 || h->val <= 0 || h->next == NULL) {
            h->key = key;
            h->val = value;
            if (h->pre != head) {
                h->pre->next = h->next;
                if (h->next) h->next->pre = h->pre;
                h->next = head->next;
                head->next->pre = h;
                head->next = h;
                h->pre = head;
            }
            return;
        }
        h = h->next;
    }
}

int main() {
    lruCacheInit(2);
    printCache();
    lruCacheSet(2, 1);
    printCache();
    lruCacheSet(1, 1);
    printCache();
    printf("%d\n", lruCacheGet(2));
    printCache();
    lruCacheSet(4, 1);
    printCache();
    printf("%d\n", lruCacheGet(1));
    printCache();

    return 0;
}
