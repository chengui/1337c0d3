#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> num;
        ListNode *head = NULL, *p = NULL;
        for (int i = 0; i < lists.size(); i++) {
            p = lists[i];
            while (p != NULL) {
                num.push_back(p->val);
                p = p->next;
            }
        }
        sort(num.begin(), num.end());
        if (!num.empty())
            head = new ListNode(num[0]);
        p = head;
        for (int i = 1; i < num.size(); i++) {
            p->next = new ListNode(num[i]);
            p = p->next;
        }
        return head;
    }
};

int main() {
    ListNode *a;
    a = new ListNode(1), a->next = new ListNode(3), a->next->next = new ListNode(5);
    ListNode *b;
    b = new ListNode(2), b->next = new ListNode(4), b->next->next = new ListNode(6);
    vector<ListNode *> lists;
    lists.push_back(a), lists.push_back(b);
    Solution solu = Solution();
    ListNode *p = solu.mergeKLists(lists);
    while (p != NULL) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}
