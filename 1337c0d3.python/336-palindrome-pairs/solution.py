from __future__ import print_function

class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def isPalindrome(word):
            return word == ''.join(reversed(word))
        res = []
        for i in xrange(len(words)):
            for j in xrange(len(words)):
                if i == j: continue
                if isPalindrome(words[i] + words[j]):
                    res.append([i, j])
        return res

if __name__ == "__main__":
    # words = ["bat", "tab", "cat"]
    words = ["abcd", "dcba", "lls", "s", "sssll"]
    s = Solution()
    print(s.palindromePairs(words))
