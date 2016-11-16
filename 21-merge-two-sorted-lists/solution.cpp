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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *p = &head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == NULL)
            p->next = l2;
        if (l2 == NULL)
            p->next = l1;
        return head.next;
    }
};

string str(ListNode *p)
{
    string ret;
    while (p != NULL)
    {
        ret += to_string(p->val) + " -> ";
        p = p->next;
    }
    ret += "NULL";
    return ret;
}

int main()
{
    ListNode *l1 = NULL, *l2 = NULL;
    ListNode a(1), b(3), c(4), d(2), e(5), f(6);
    l1=&a, a.next=&b, b.next=&c, l2=&d, d.next=&e, e.next=&f;
    Solution s = Solution();
    cout << str(s.mergeTwoLists(l1, l2)) << endl;
}
