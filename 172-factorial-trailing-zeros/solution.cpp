#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // use long long to avoid overflow
        long long pow = 0;
        long long i = 5;
        long long m = 0;
        do {
            pow += (m = n / i);
            i *= 5;
        } while (m != 0);
        return pow;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.trailingZeroes(100) << endl;
    cout << solu.trailingZeroes(1808548329) << endl;
}
