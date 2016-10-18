#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        do
        {
            if (num == 0)
            {
                num = sum;
                sum = 0;
            }
            while (num > 0)
            {
                sum += num % 10;
                num = num / 10;
            }
        } while (sum >= 10);
        return sum;
    }
};

int main()
{
    int num = 0;
    Solution s = Solution();
    cout << s.addDigits(num) << endl;
}
