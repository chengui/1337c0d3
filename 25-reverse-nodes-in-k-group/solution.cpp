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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = NULL, *q = NULL, *r = NULL, *t = NULL;
        int idx = 0;
        p = &dummy;
        q = p;
        while (q != NULL) {
            if (idx < k) {
                q = q->next;
                idx++;
            } else {
                t = q;
                while (idx > 1) {
                    r = p->next;
                    p->next = r->next;
                    r->next = q->next;
                    q->next = r;
                    if (idx == k)
                        t = r;
                    idx--;
                }
                p = t;
                q = t;
                idx = 0;
            }
        }
        return dummy.next;
    }
};

int main() {
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    int k = 3;
    Solution solu = Solution();
    ListNode *p = solu.reverseKGroup(&a, k);
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
