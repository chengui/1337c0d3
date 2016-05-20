from __future__ import print_function

class Solution(object):
    """
    Split the given string to two lists by separate of vowels, one
    including non-vowels words, another including vowels, then concat
    the first list and the second list reversed, which genrate the
    excepted result.
    """
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        sep = 'aoeiuAOEIU'
        res1 = []
        res2 = []
        beg = 0
        for i in range(len(s)):
            if s[i] in sep:
                res1.append(s[beg:i])
                res2.append(s[i])
                beg = i + 1
        if beg < len(s): res1.append(s[beg:])
        riter_res2 = reversed(res2)
        res = ''
        for i in range(len(res2)):
            res += res1[i] + res2[-(i+1)]
        if len(res2) < len(res1): res += res1[-1]
        return res

if __name__ == "__main__":
    # str = 'hello wOrld'
    str = 'aA'
    s = Solution()
    print(s.reverseVowels(str))
