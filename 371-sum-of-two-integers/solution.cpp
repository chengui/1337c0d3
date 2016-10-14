#include <iostream>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        int abit = 0, bbit = 0;
        int c = 0, carry = 0;
        for(int i = 0; i < 32; i++)
        {
            abit = (a>>i)&1;
            bbit = (b>>i)&1;
            c = c^((abit^bbit^carry)<<i);
            carry = (abit|bbit)&(abit|carry)&(bbit|carry);
        }
        return c;
    }
};

int main()
{
    int a = 12, b = 2;
    Solution s = Solution();
    cout << s.getSum(a, b) << endl;
}
