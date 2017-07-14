#!/usr/bin/env python
# encoding: utf-8

class Solution:
    # @return a string
    def intToRoman(self, num):
        symbol= {1: 'I',
            5: 'V',
            10: 'X',
            50: 'L',
            100: 'C',
            500: 'D',
            1000: 'M',
           }
        base = [1000, 100, 10, 1]
        string = ''
        for b in base:
            i = num / b;
            num = num % b;
            if i == 0:
                continue
            if i == 9 or i == 4:
                string += symbol[b]
                string += symbol[(i + 1) * b]
            else:
                if i >= 5:
                    string += symbol[5 * b]
                    i = i - 5
                if i > 0:
                    string += symbol[b] * i
        return string

if __name__ == "__main__":
    solu = Solution()
    print solu.intToRoman(1001)
