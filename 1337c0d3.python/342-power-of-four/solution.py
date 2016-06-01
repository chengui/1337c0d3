from __future__ import print_function

class Solution(object):
    """
    Assigned a signed 32bits integer, so it will be in such
    a map:
      >>> map(lambda x: 1<<x, range(0, 32, 2))

    Pattern of Power-of-Four is the amount of 1 in 32 bits
    always keeping 1, and this 1 only staying at even bit.
    Like: 0001b, 0100b
    """
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        cnt = 0
        for i in xrange(0, 32):
            if cnt > 1:
                return False
            if i % 2 == 1 and num & 1 == 1:
                return False
            cnt += num & 1
            num = num >> 1
        return cnt == 1

if __name__ == "__main__":
    num = 16
    s = Solution()
    print(s.isPowerOfFour(num))
