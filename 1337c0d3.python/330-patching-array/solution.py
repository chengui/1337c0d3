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
        patches = []
        bpow, mxrange = 0, 0
        nums.append(n)
        for num in nums:
            while mxrange < num:
                if 2**bpow not in nums[:-1]: patches.append(bpow)
                bpow, mxrange = bpow + 1, 2**(1+bpow) - 1
            mxrange += num
            if mxrange >= n: break
        print(patches)
        return len(patches)
       
if __name__ == "__main__":
    # nums, n = [1, 3], 6
    # nums, n = [1, 2, 2], 5
    # nums, n = [1, 5, 10], 20
    # nums, n = [], 8
    nums, n = [1, 2, 31, 33], 2147483647
    s = Solution()
    print(s.minPatches(nums, n))
