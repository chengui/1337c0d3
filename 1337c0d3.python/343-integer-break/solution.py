from __future__ import print_function

class Solution(object):
    """
    Range 2 to 13 and find the regularity
    """
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n % 3 == 0:
            return 3**(n/3)
        if n % 3 == 1:
            return 2*2*3**(n/3-1)
        return 2*3**(n/3)

if __name__ == "__main__":
    n = 5
    s = Solution()
    print(s.integerBreak(n))

