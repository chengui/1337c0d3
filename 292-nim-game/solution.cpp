#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n&3;
    }
};

int main()
{
    int n = 7;
    Solution s = Solution();
    cout << s.canWinNim(n) << endl;
}
