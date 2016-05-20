from __future__ import print_function

class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        def unique(dct, k):
            if k not in dct:
                dct[k] = 1
            return dct
        res1 = filter(lambda k: k in nums1 and k in nums2, nums1+nums2)
        res2 = reduce(unique, res1, {})
        return res2.keys()

if __name__ == "__main__":
    nums1 = [1, 2, 2, 3]
    nums2 = [2, 2]
    s = Solution()
    print(s.intersection(nums1, nums2))
