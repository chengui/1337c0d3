from __future__ import print_function

class Solution(object):
    """
    Intersection presents value in both list A and list B, so filter
    out all values both in list A and B by using 'filter', then unique
    the results with hash dict.
      >>> filter(lambda k: k in nums1 and k in nums2, nums1+nums2)

    To save more time, use the short list (S) as iterator, the long
    list (L) as hash checking.
      >>> filter(lambda k: k in L, S)
    """
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
        if len(nums1) < len(nums2):
            S, L = nums1, nums2
        else:
            S, L = nums2, nums1
        res1 = filter(lambda k: k in L, S)
        res2 = reduce(unique, res1, {})
        return res2.keys()

if __name__ == "__main__":
    nums1 = [1, 2, 2, 3]
    nums2 = [2, 2]
    s = Solution()
    print(s.intersection(nums1, nums2))
