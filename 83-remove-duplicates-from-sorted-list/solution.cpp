#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#if __cplusplus != 201103L
#define to_string(x) static_cast<std::ostringstream &>(std::ostringstream() << std::dec << x).str()
#endif

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q = head->next;
        while (p != NULL && q != NULL)
        {
            if (p->val == q->val)
            {
                p->next = q->next;
                q = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};

string str(ListNode *head)
{
    string ret = "";
    while (head != NULL)
    {
        ret += to_string(head->val) + "->";
        head = head->next;
    }
    ret += "NULL";
    return ret;
}

int main()
{
    ListNode *head = NULL;
    ListNode a(1), b(1), c(2), d(3), e(3);
    head = &a, a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    Solution s = Solution();
    cout << str(s.deleteDuplicates(head)) << endl;
}
