from __future__ import print_function

class Solution(object):
    """
    It is easy to give a solution with O(n*sizeof(int)), count all bits with '>>' and '&'
      >>> map(lambda i: reduce(lambda x, y: x + (i>>y&1), range(32), 0), range(num+1))
    """
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return map(lambda i: reduce(lambda x, y: x + (i>>y&1), range(32), 0), range(num+1))

if __name__ == "__main__":
    num = 5
    s = Solution()
    print(s.countBits(num))
