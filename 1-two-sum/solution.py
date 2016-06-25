from __future__ import print_function

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        from itertools import combinations
        for it in combinations(range(len(nums)), 2):
            if nums[it[0]] + nums[it[1]] == target: return list(it)
        return []

if __name__ == "__main__":
    target, nums = 9, [2, 7, 11, 15]
    s = Solution()
    print(s.twoSum(nums, target))
