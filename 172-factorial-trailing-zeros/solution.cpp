#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int pow = 0;
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j % 5 == 0) {
                pow++;
                j = j / 5;
            }
        }
        return pow;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.trailingZeroes(100) << endl;
}
