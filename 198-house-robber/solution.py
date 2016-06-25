from __future__ import print_function

class Solution(object):
    """
    Recursive solution. Separate the problem to two parts, one is
    first room selected, which means the next not selected, reduce
    this part to nums[2:]; another is first room not selected,
    reduce this part to nums[1:]
      >>> max(nums[0], rob(nums[2:]), rob(nums[1:]))
    Reduce solution. Iterate the recursive solution by storing each
    previous previous maxinum sum and previous maxinum sum
      >>> reduce(lambda t, x: (t[1], max(t[0]+x, t[1])), nums, (0, 0))[1]
    """
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda t, x: (t[1], max(t[0]+x, t[1])), nums, (0, 0))[1]

if __name__ == "__main__":
    nums = [3, 1, 1, 6, 8] 
    s = Solution()
    print(s.rob(nums))
