#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define SSTR(x) static_cast<std::ostringstream &>(std::ostringstream() << std::dec << x).str()

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
    void deleteNode(ListNode* node) {
        while (node != NULL && node->next != NULL)
        {
            node->val = node->next->val;
            if (node->next->next == NULL)
                node->next = NULL;
            node = node->next;
        }
    }
};

string str(ListNode* head)
{
    string ret = "";
    while (head != NULL)
    {
        ret += SSTR(head->val) + "->";
        head = head->next;
    }
    ret += "NULL";
    return ret;
}

int main()
{
    ListNode *head = NULL, a(1), b(2), c(3), d(4), e(5);
    head = &a, a.next = &b, b.next = &c, c.next = &d, d.next = &e;
    Solution s = Solution();
    cout << str(head) << endl;
    s.deleteNode(&c);
    cout << str(head) << endl;
}
