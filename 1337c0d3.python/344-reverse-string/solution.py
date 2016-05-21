from __future__ import print_function

class Solution(object):
    """
    Simply use reversed
    """
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(reversed(s))

if __name__ == "__main__":
    str = 'hello'
    s = Solution()
    print(s.reverseString(str)) 
