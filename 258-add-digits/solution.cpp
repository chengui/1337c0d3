#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        do
        {
            sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        } while (sum >= 10);
        return sum;
    }
};

int main()
{
    int num = 128;
    Solution s = Solution();
    cout << s.addDigits(num) << endl;
}
