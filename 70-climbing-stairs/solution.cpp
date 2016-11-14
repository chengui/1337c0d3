#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, t = 0;
        for (int i = 0; i < n; i++) {
            t = b;
            b =  a + b;
            a = t;
        }
        return b;
    }
};

int main()
{
    int n = 4;
    Solution s = Solution();
    cout << s.climbStairs(n) << endl;
}
