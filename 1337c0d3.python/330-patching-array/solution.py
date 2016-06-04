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
        marked = dict()
        for num in nums:
            for i in marked.keys():
                if num+i not in marked: marked[num+i] = True
            if num not in marked: marked[num] = True
        npatch = 0
        for num in range(1, n+1):
            if len(marked) == n: break
            if num not in marked:
                npatch += 1
                for i in marked.keys():
                    if num+i not in marked: marked[num+i] = True
                if num not in marked: marked[num] = True
        return npatch
        
if __name__ == "__main__":
    # nums, n = [1, 3], 6
    # nums, n = [1, 2, 2], 5
    # nums, n = [1, 5, 10], 20
    nums, n = [1, 2, 31, 33], 2147483647
    s = Solution()
    print(s.minPatches(nums, n))
