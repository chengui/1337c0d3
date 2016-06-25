from __future__ import print_function

class Solution(object):
    """
    The simple way is to count the frequence by using reduce first,
    and then sort by the frequence.
    And abviously there are serveral ways to do sorting in python.
      >>> d = dict([(i, 1000000-i) for i in range(1000000)])
      >>> time res = sorted(d, key=d.get)
      CPU times: user 0.16 s, sys: 0.00 s, total: 0.16 s
      Wall time: 0.16 s
      >>> time res = sorted(d, cmp=lambda x,y: cmp(d.get(x), d.get(y)))
      CPU times: user 0.46 s, sys: 0.00 s, total: 0.46 s
      Wall time: 0.46 s
      >>> time res = sorted(d.items(), key=operator.itemgetter(1))
      CPU times: user 2.49 s, sys: 0.02 s, total: 2.52 s
      Wall time: 2.52 s
    """
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def count(dct, k):
            if k not in dct:
                dct[k] = 1
            else:
                dct[k] += 1
            return dct
        freq = reduce(count, nums, {})
        res = sorted(freq, key=freq.get, reverse=True)
        return res[:k]

if __name__ == "__main__":
    # nums = [1, 1, 1, 2, 2, 3, 3, 3]
    # k = 2
    limit = 1000000
    nums = dict([(i, limit - i) for i in range(limit)])
    k = 10
    s = Solution()
    print(s.topKFrequent(nums, k))
