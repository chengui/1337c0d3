#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};

int main()
{
    int n = 4;
    Solution s = Solution();
    cout << s.isPowerOfTwo(n) << endl;
}
