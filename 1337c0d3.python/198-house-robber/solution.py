from __future__ import print_function

class Solution(object):
    """
    Recursive solution. Separate the problem to two parts, one is
    first room selected, which means the next not selected, reduce
    this part to nums[2:]; another is first room not selected,
    reduce this part to nums[1:]
      >>> max(nums[0], rob(nums[2:]), rob(nums[1:]))
    """
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums[0], nums[1])
        return max(nums[0] + self.rob(nums[2:]), self.rob(nums[1:]))

if __name__ == "__main__":
    nums = [3, 1, 1, 6, 8] 
    s = Solution()
    print(s.rob(nums))
