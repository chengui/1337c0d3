#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            sum += n & 1;
            n = n >> 1;
        }
        return sum;
    }
};

int main()
{
    uint32_t n = 0;
    Solution s = Solution();
    cout << s.hammingWeight(n) << endl;
}
