#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};

int main()
{
    int n = 4;
    Solution s = Solution();
    cout << s.canWinNim(n) << endl;
}
