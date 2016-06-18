from __future__ import print_function

class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def reversedstr(word):
            return ''.join(reversed(word))
        def isPalindrome(word):
            return word == ''.join(reversed(word))
        res = []
        for i in xrange(len(words)):
            for j in xrange(len(words[i])):
                substr1, substr2 = words[i][:j], words[i][j:]
                if isPalindrome(substr1) and reversedstr(substr2) in words:
                    k = words.index(reversedstr(substr2))
                    if k != i: res.append([k, i])
                if isPalindrome(substr2) and reversedstr(substr1) in words:
                    k = words.index(reversedstr(substr1))
                    if k != i: res.append([i, k])
        return res

if __name__ == "__main__":
    # words = ["bat", "tab", "cat"]
    words = ["abcd", "dcba", "lls", "s", "sssll"]
    s = Solution()
    print(s.palindromePairs(words))
