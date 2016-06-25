#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* array2List(int* array, int n) {
    ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; i++) {
        if (p == NULL) {
            head = p = new ListNode(array[i]);
        } else {
            p->next = new ListNode(array[i]);
            p = p->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    ListNode *p = head;
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = 0, carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
            l2 = l2->next;
        }
        if (carry) {
            p->next = new ListNode(carry);
        }
        return head->next;        
    }
};

int main() {
    int a1[3] = {2, 4, 3};
    int a2[3] = {5, 6, 4};
    ListNode *l1 = array2List(a1, 3);
    ListNode *l2 = array2List(a2, 3);
    Solution s = Solution();
    printList(s.addTwoNumbers(l1, l2));
}
