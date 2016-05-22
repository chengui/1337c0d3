from __future__ import print_function

class Solution(object):
    """
    Assigned a signed 32bits integer, so it will be in such
    a map:
      >>> map(lambda x: 3**x, range(0, 20))
    """
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num in map(lambda x: 3**x, xrange(0, 20))

if __name__ == "__main__":
    num = 81 
    s = Solution()
    print(s.isPowerOfFour(num))
