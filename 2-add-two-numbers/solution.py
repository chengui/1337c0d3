from __future__ import print_function

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def array2List(lst):
    head, p = None, None
    for i in lst:
        if p is None:
            head = p = ListNode(i)
        else:
            p.next = ListNode(i)
            p = p.next
    return head

def printList(head):
    p, strs = head, ""
    while p is not None:
        strs += '%d -> ' % (p.val)
        p = p.next
    print(strs)

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head, p, c = None, None, 0
        while l1 is not None or l2 is not None:
            v = (l1 and l1.val or 0) + (l2 and l2.val or 0) + c
            v, c = v%10, v/10
            if p is None:
                head = p = ListNode(v)
            else:
                p.next = ListNode(v)
                p = p.next
            if l1 is not None: l1 = l1.next
            if l2 is not None: l2 = l2.next
        if c > 0: p.next = ListNode(c)
        return head

if __name__ == "__main__":
    a1 = [8]
    a2 = [9]
    l1 = array2List(a1)
    l2 = array2List(a2)
    s = Solution()
    printList(s.addTwoNumbers(l1, l2))
