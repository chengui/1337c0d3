from __future__ import print_function

class Solution(object):
    """
    Assigned a signed 32bits integer, so it will be in such
    a map:
      >>> map(lambda x: 1<<x, range(0, 32, 2))

    Pattern of Power-of-Four is the amount of 1 in 32 bits
    always keeping 1, and this 1 only staying at even bit.
    Like: 0001b, 0100b

    Use reduce to compute 1 bits in num:
      >>> reduce(lambda s, x: s+((num>>x)&1), xrange(0,32,2), 0)
    """
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1: return True
        if num % 2 == 1: return False
        if reduce(lambda s, x: s + ((num>>x)&1), xrange(1, 32, 2), 0) > 0: return False
        return reduce(lambda s, x: s + ((num>>x)&1), xrange(0, 32, 2), 0) == 1

if __name__ == "__main__":
    num = 14
    s = Solution()
    print(s.isPowerOfFour(num))
