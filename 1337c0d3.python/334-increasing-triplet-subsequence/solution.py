from __future__ import print_function

class Solution(object):
    """
    Use a ladder to assist, it tracks max values in max-len-is-one
    sequence, max-len-is-two sequence, max-len-is-three sequence,
    so if produced max-len-is-three sequence, return True; else
    update the max values in these sequences
    """
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3: return False
        ladder = [nums[0], None, None]
        for i in range(1, len(nums)):
            if ladder[2] is not None: return True
            if ladder[1] is not None and nums[i] > ladder[1]:
                ladder[2] = nums[i]
            elif nums[i] > ladder[0]:
                ladder[1] = nums[i]
            else:
                ladder[0] = nums[i]
        return ladder[2] is not None

if __name__ == "__main__":
    # nums = [1, 2, 3, 4, 5]
    # nums = [5, 4, 3, 2, 1]
    # nums = [1, 3, 2, 3, 2, 4]
    nums = range(10000, 0, -1)
    s = Solution()
    print(s.increasingTriplet(nums))
