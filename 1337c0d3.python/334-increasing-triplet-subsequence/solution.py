from __future__ import print_function

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 2: return False
        return self.increasingTripletRecursive(nums[:], nums[0], 3)

    def increasingTripletRecursive(self, nums, minNum, maxLen):
        if maxLen <= 0:
            return True
        if len(nums) == 0:
            return False
        if len(nums) == 1:
            if nums[0] > minNum and maxLen == 1: return True
            return False
        if nums[0] < nums[1]:
            a = self.increasingTripletRecursive(nums[2:], nums[1], maxLen-2)
            nums[0], nums[1] = nums[1], nums[0]
            b = self.increasingTripletRecursive(nums[1:], nums[1], maxLen)
            return a or b
        return self.increasingTripletRecursive(nums[1:], nums[1], maxLen)

if __name__ == "__main__":
    # nums = [1, 2, 3, 4, 5]
    # nums = [5, 4, 3, 2, 1]
    nums = [1, 3, 2, 3, 2, 4]
    s = Solution()
    print(s.increasingTriplet(nums))
