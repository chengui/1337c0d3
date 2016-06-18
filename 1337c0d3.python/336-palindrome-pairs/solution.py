from __future__ import print_function

class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        res = []
        for i in xrange(len(words)):
            if words[i] == "": continue
            rword = ''.join(reversed(words[i]))
            if words[i] != rword:
                if rword in words:
                    res.append([i, words.index(rword)])
            elif "" in words:
                res.append([i, words.index("")])
                res.append([words.index(""), i])
            for j in xrange(1, len(words[i])):
                substr1, substr2 = words[i][:j], words[i][j:]
                rsubstr1, rsubstr2 = ''.join(reversed(substr1)), ''.join(reversed(substr2))
                if substr1 == rsubstr1 and rsubstr2 in words:
                    res.append([words.index(rsubstr2), i])
                if substr2 == rsubstr2 and rsubstr1 in words:
                    res.append([i, words.index(rsubstr1)])
        return res

if __name__ == "__main__":
    words = ["a", ""]
    # words = ["bat", "tab", "cat"]
    # words = ["abcd", "dcba", "lls", "s", "sssll"]
    s = Solution()
    print(s.palindromePairs(words))
