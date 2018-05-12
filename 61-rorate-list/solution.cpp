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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *fast = NULL;
        ListNode *slow = NULL;

        if (head == NULL || k == 0)
            return head;

        fast = slow = head;
        for (; k > 0; k--) {
            fast = fast->next;
            if (fast == NULL)
                fast = head;
        }

        if (fast == head)
            return head;
        for (; fast->next != NULL; fast = fast->next, slow = slow->next);

        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};

int main() {
    int k = 2;
    ListNode *head = NULL, a(1), b(2), c(3), d(4), e(5);
    head = &a, a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    Solution solu = Solution();
    ListNode *r = solu.rotateRight(head, k);
    while (r) {
        cout << r->val << "->";
        r = r->next;
    }
    cout << endl;
}
