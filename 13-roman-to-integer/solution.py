#!/usr/bin/env python
# encoding: utf-8

class Solution:
    # @return an integer
    def romanToInt(self, s):
        symbol = {'I': 1,
                  'V': 5,
                  'X': 10,
                  'L': 50,
                  'C': 100,
                  'D': 500,
                  'M': 1000,
                 }

        total = 0
        prev = 'M'
        for num in s:
            if symbol[prev] < symbol[num]:
                total = total + symbol[num] - 2 * symbol[prev]
            else:
                total = total + symbol[num]
            prev = num

        return total

if __name__ == "__main__":
    str = "IV"
    s = Solution()
    print(s.romanToInt(str))
