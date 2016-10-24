#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        vector<ListNode*> stack;
        ListNode *p = head;
        while (p != NULL)
        {
            stack.push_back(p);
            p = p->next;
        }
        head = p = stack.back();
        stack.pop_back();
        while (!stack.empty())
        {
            p->next = stack.back();
            stack.pop_back();
            p = p->next;
        }
        if (p != NULL) p->next = NULL;
        return head;
    }
};

string str(ListNode *head)
{
    ListNode *p = head;
    string ret = "";
    while (p != NULL)
    {
        ret += to_string(p->val) + " -> ";
        p = p->next;
    }
    return ret;
}

int main()
{
    ListNode *head = NULL;
    ListNode a(1), b(2), c(3), d(4);
    head = &a, a.next = &b, b.next = &c, c.next = &d;
    Solution s = Solution();
    cout << str(s.reverseList(head)) << endl;
}
