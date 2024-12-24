#include <iostream>
#include <algorithm> // Include the algorithm header for swap

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)
      return list1 ? list1 : list2;
    if (list1->val > list2->val)
      std::swap(list1, list2); // Use std::swap
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};

// Function to print the linked list in the specified format
void printList(ListNode* head) {
    std::cout << "[";
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr) {
            std::cout << ", ";
        }
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedListHead = solution.mergeTwoLists(list1, list2);

    printList(mergedListHead);

    return 0;
}