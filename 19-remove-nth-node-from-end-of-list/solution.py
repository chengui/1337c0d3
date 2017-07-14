#!/usr/bin/env python
# encoding: utf-8

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        #
        if head is None:
            return None

        dummy = ListNode(0)
        dummy.next = head
        fast = dummy
        slow = dummy

        while n:
            fast = fast.next
            n = n - 1

        while fast is not None and fast.next is not None:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next

if __name__ == "__main__":
    a, b, c, d, e = ListNode(1), ListNode(2), ListNode(3), ListNode(4), ListNode(5)
    a.next = b; b.next = c; c.next = d; d.next = e;
    solu = Solution()
    p = solu.removeNthFromEnd(a, 2)
    while p is not None:
        print p.val
        p = p.next
