from __future__ import print_function

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        def count(dct, k):
            if k not in dct:
                dct[k] = 1
            else:
                dct[k] += 1
            return dct
        nums1 = reduce(count, nums1, {})
        nums2 = reduce(count, nums2, {})
        if len(nums1) < len(nums2):
            S, L = nums1, nums2
        else:
            S, L = nums2, nums1
        def extend(lst, k):
            if k[0] in L:
                lst.extend([k[0]]*min(L[k[0]], k[1]))
            return lst
        return reduce(extend, S.items(), []) 

if __name__ == "__main__":
    # nums1 = [1, 2, 2, 1]
    # nums2 = [2, 2]
    nums1 = [1, 2]
    nums2 = [1, 1]
    s = Solution()
    print(s.intersect(nums1, nums2))
