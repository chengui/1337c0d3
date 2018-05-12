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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p, *q;
        int count = 0, last = 0;
        p = &dummy;
        q = p->next;
        last = q->val;
        while (q != NULL) {
            if (q->val != last) {
                last = q->val;
                if (count > 1) {
                    p->next = q;
                    count = 1;
                } else {
                    p = p->next;
                }
            } else {
                count++;
            }
            q = q->next;
        }
        if (count > 1) {
            p->next = q;
        }
        return dummy.next;
    }
};

int main() {
    ListNode *head, a(1), b(1), c(1), d(2), e(3);
    head = &a, a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    Solution solu = Solution();
    ListNode *p = solu.deleteDuplicates(head);
    while (p) {
        cout << p->val << "->";
    }
    cout << endl;
}
