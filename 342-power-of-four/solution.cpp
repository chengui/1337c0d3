#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        if ((num & (num - 1)) != 0)
            return false;
        return num & 0x55555555;
    }
};

int main()
{
    int num = 56;
    Solution s = Solution();
    cout << s.isPowerOfFour(num) << endl;
}
