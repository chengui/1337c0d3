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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // return if NULL
        if (head == NULL)
            return NULL;
        // define a dummy head, dummyHead->next = head;
        ListNode dummyHead(0); dummyHead.next = head;
        ListNode *fast = &dummyHead, *slow = &dummyHead;
        // let fast_pointer be n nodes ahead than slow_pointer
        while (n--) {
            fast = fast->next;
        }
        // move fast_pointer and slow_pointer in the same pace
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        // delete slow->next
        slow->next = slow->next->next;
        // return the actual head
        return dummyHead.next;
    }
};

int main() {
    ListNode *root = NULL;
    ListNode a(1), b(2), c(3), d(4), e(5);
    root = &a, a.next = &b, b.next = &c, c.next = &d , d.next = &e;
    int n = 2;
    Solution solu = Solution();
    ListNode *res = solu.removeNthFromEnd(root, n);
    while (res != NULL) {
        cout << res->val << " -> ";
        res = res->next;
    }
    cout << "NULL" << endl;
}
