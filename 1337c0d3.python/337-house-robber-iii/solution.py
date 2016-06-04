from __future__ import print_function

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def __str__(self):
        return "%s" % self.val

class Solution(object):
    """
    Recursive solution. Compute 'left' as left selected, 'lleft' as left unselected,
    and 'right' as right selected, 'rright' as right unselected, thus the final result
    will be max(left+right/*root unselected*/, root.val+lleft+rright/*root selected*/)

    Post-order traversal. Calculate two values (in, out), which means w/ or w/o root
    selected. if w/ root, get rid of left and right children (supposed to be lout, rout),
    which results out root.val+lout+rout; else four cases would be considered, as like:
    (w/-left+w/right, w/o-left+w/right, w/-left+w/o-right, w/o-left+w/o-right), check out
    the maximum value from them. The final result will be the maximum of the two.
    """
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def traversal(root):
            if root is None: return (0, 0)
            (lin, lout) = traversal(root.left)
            (rin, rout) = traversal(root.right)
            return (root.val+lout+rout, max(lin+rin, lout+rin, lin+rout, lout+rout))
        if root is None: return 0
        return max(traversal(root))

if __name__ == "__main__":
    # root = TreeNode(3)
    # root.left = TreeNode(2)
    # root.right = TreeNode(3)
    # root.left.right = TreeNode(3)
    # root.right.right = TreeNode(1)
    root = TreeNode(3)
    root.left, root.right = TreeNode(4), TreeNode(5)
    root.left.left, root.left.right = TreeNode(3), TreeNode(1)
    root.right.right = TreeNode(1)
    # root = TreeNode(4)
    # root.left, root.left.left, root.left.left.left = TreeNode(1), TreeNode(2), TreeNode(3)
    s = Solution()
    print(s.rob(root))
