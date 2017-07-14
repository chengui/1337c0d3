#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        int mask = 0x80000000;
        int sub = 0, res = 0, bits = 32;
        int flag_dividend = dividend & mask;
        int flag_divisor = divisor & mask;
        if (flag_dividend)
            dividend = ~dividend + 1;
        if (flag_divisor)
            divisor = ~divisor + 1;

        while (bits) {
            if (dividend & mask)
                sub = (sub << 1) | 1;
            else
                sub = sub << 1;
            if ((sub - divisor) & mask) {
                res = res << 1;
            } else {
                sub = sub - divisor;
                res = (res << 1) | 1;
            }
            dividend <<= 1;
            bits--;
        }
        if (flag_dividend ^ flag_divisor)
            return (~res + 1);
        return res;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.divide(4, 2) << endl;
}
