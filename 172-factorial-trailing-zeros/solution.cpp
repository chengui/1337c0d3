#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int pow = 0;
        int i = 5;
        int m = 0;
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
