from __future__ import print_function

class Solution(object):
    """
    Find from small number. Mark it when a number picked, and
    mark all numbers it can produce, then find another smallest
    one from the unmarked numbers.
    """
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        import math
        import itertools
        nlen, plen, patches, removes = 1, 0, dict(), dict()
        nums = filter(lambda i: i<=n, nums)
        while nlen <= len(nums):
            for com in itertools.combinations(range(len(nums)), nlen):
                nsum = sum(map(nums.__getitem__, com))
                if nsum & (nsum - 1) == 0 and nsum not in patches:
                    patches[nsum] = True
                    map(lambda i: nums.__setitem__(i, -1), com)
            nums = filter(lambda i: i != -1, nums)
            nlen += 1
        return 1 + int(math.log(n - sum(nums), 2)) - len(patches)
       
if __name__ == "__main__":
    # nums, n = [1, 3], 6
    # nums, n = [1, 2, 2], 5
    # nums, n = [1, 5, 10], 20
    # nums, n = [], 8
    # nums, n = [1, 2, 31, 33], 2147483647
    nums, n = [2, 4, 14, 18, 20, 25, 25, 35, 73, 94], 42
    s = Solution()
    print(s.minPatches(nums, n))
