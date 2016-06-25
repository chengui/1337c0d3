from __future__ import print_function

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def link(self, next):
        self.next = next

    def __str__(self):
        str, node = "", self
        while node is not None:
            str += "%d->" % node.val
            node = node.next
        str += 'NULL'
        return str

class Solution(object):
    """
    Use a temp node to store even ListNodes, and head to
    store odd ListNodes, merge the two Linked Lists after
    process.
    """
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None: return None
        i, even = 0, ListNode(0)
        enode, onode, node = even, head, head
        while node is not None:
            i += 1
            if i % 2 == 0:
                enode.next = node
                onode.next = node.next
                enode = enode.next or enode
                onode = onode.next or onode
            node = node.next
        enode.next = None
        onode.next = even.next
        return head
        
if __name__ == "__main__":
    nodes = [ListNode(i) for i in xrange(1, 6)]
    map(lambda i: nodes[i].link(nodes[i+1]), xrange(0, 4))
    s = Solution()
    print(s.oddEvenList(nodes[0]))
