from __future__ import print_function

class Solution(object):
    """
    First count the numbers in both nums1 and nums2, and then check out the values
    in both nums1 and nums2 with the less counts to generate a duplicated list
      >>> reduce(lambda l, t: t[0] not in L and l or l.extend([t[0]]*min(L[t[0]], t[1])) or l, S.items(), [])
    """
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        count = lambda d, k: d.update({k: k in d and d[k]+1 or 1}) or d
        nums1 = reduce(count, nums1, {})
        nums2 = reduce(count, nums2, {})
        if len(nums1) < len(nums2):
            S, L = nums1, nums2
        else:
            S, L = nums2, nums1
        extend = lambda l, t: t[0] not in L and l or l.extend([t[0]]*min(L[t[0]], t[1])) or l
        return reduce(extend, S.items(), []) 

if __name__ == "__main__":
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    # nums1 = [1, 2]
    # nums2 = [1, 1]
    s = Solution()
    print(s.intersect(nums1, nums2))
