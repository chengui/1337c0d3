#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = n;
        set<int> sums;
        while (!sums.count(sum) && sum != 1)
        {
            if (!sums.count(sum))
                sums.insert(sum);

            int dec = 0, left = sum;
            sum = 0;
            while (left > 0)
            {
                dec = left % 10;
                sum += dec * dec;
                left = left / 10;
            }
            cout << sum << endl;
        }
        return sum == 1;
    }
};

int main()
{
    int n = 18;
    Solution s = Solution();
    cout << s.isHappy(n) << endl;
}
