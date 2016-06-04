from __future__ import print_function

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        lleft, rright, left, right = 0, 0, 0, 0
        if root.left is not None:
            left = self.rob(root.left)
            lleft = self.rob(root.left.left) + self.rob(root.left.right)
        if root.right is not None:
            rigth = self.rob(root.right)
            rright = self.rob(root.right.left) + self.rob(root.right.right)
        return max(left+right, root.val+lleft+rright)        

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(1)
    s = Solution()
    print(s.rob(root))
