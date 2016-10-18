#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        return !(num%9) ? 9: (num%9);
    }
};

int main()
{
    int num = 279;
    Solution s = Solution();
    cout << s.addDigits(num) << endl;
}
