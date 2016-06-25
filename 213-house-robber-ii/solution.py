from __future__ import print_function

class Solution(object):
    """
    Separate the problem to two parts, one is nums[0] selected, plus
    the maximum rob of nums[2:-1], for nums[1] and nums[-1] can't be
    selected; another is nums[0] not selected, then compute the maximum
    rob of nums[1:]. Compare the two maximum rob to get final result.
    """
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums[0], nums[1])
        a = nums[0] + reduce(lambda t, x: (t[1], max(x+t[0], t[1])), nums[2:-1], (0, 0))[1]
        b = reduce(lambda t, x: (t[1], max(x+t[0], t[1])), nums[1:], (0, 0))[1]
        return max(a, b)

if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5]
    s = Solution()
    print(s.rob(nums))
