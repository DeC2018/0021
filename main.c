#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* h = &head;

    if (l1 == NULL && l2 == NULL)
        return NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            h->next = l1;
            l1 = l1->next;
            h = h->next;
        } else {
            h->next = l2;
            l2 = l2->next;
            h = h->next;
        }
    }

    if (l1) {
        h->next = l1;
    }
    if (l2) {
        h->next = l2;
    }

    return head.next;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf(", ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

int main() {
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode* mergedListHead = mergeTwoLists(list1, list2);

    printList(mergedListHead);

    return 0;
}