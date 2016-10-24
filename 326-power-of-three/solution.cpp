#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int maxpow = (int)pow(3, 19);
        return maxpow % n == 0;

    }
};

int main()
{
    int n = 81;
    Solution s = Solution();
    cout << s.isPowerOfThree(n) << endl;
}
