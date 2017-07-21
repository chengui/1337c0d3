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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        if (headA == headB)
            return headA;

        ListNode *p = NULL, *q = NULL, *last = NULL;

        p = headA;
        while (p->next != NULL) {
            p = p->next;
        }
        last = p;
        p->next = headB;

        p = q = headA;
        while (p != NULL && q != NULL) {
            if (q->next != NULL) {
                q = q->next->next;
            } else {
                q = NULL;
            }
            p = p->next;

            if (p == q)
                break;
        }

        if (p == NULL || q == NULL) {
            last->next = NULL;
            return NULL;
        }

        p = headA;
        while(p != NULL && q != NULL && p != q) {
            q = q->next;
            p = p->next;
        }
        last->next = NULL;
        return p;

    }
};

int main() {
    ListNode a1(1), a2(2), b1(11), b2(12), b3(13), c1(21), c2(22), c3(23);
    a1.next = &a2, a2.next = &c1, b1.next = &b2, b2.next = &b3, b3.next = &c1, c1.next = &c2, c2.next = &c3;
    // ListNode a1(1);
    // ListNode a1(1), a2(2);
    // a1.next = &a2;
    Solution solu = Solution();
    // ListNode *p = solu.getIntersectionNode(&a1, &b1);
    ListNode *p = solu.getIntersectionNode(&a1, &a1);
    // ListNode *p = solu.getIntersectionNode(&a1, &a2);
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << endl;
}
