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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummyhead(0);
        ListNode *p, *q;
        dummyhead.next = head;
        p = &dummyhead;
        q = head;
        while (p != NULL && p->next != NULL && q->next !=NULL) {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
            p = q;
            q = q->next;
        }
        return dummyhead.next;
    }
};

int main() {
    ListNode *head = NULL;
    head = new ListNode(1), head->next = new ListNode(2), head->next->next = new ListNode(3), head->next->next->next = new ListNode(4);
    Solution solu = Solution();
    ListNode *p = solu.swapPairs(head);
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
