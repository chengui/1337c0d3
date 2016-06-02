from __future__ import print_function

class Solution(object):
    """
    Use a stack to simulate preorder of a binary tree, and
    finally only '#' staying at the stack means a binary
    tree preorder traversal completed.
    """
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        def stack_push(s, v):
            if len(s) > 0 and s[-1] == '#' and v == '#':
                s.pop()
                if len(s) == 0: return False
                s.pop()
                stack_push(s, '#')
            else:
                s.append(v)
            return True
        s = []
        for val in preorder.split(','):
            if not stack_push(s, val): return False
        return len(s) == 1 and s[0] == '#'

if __name__ == "__main__":
    # preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
    preorder = "1,#,#"
    s = Solution()
    print(s.isValidSerialization(preorder))
