#include <iostream>
using  namespace std;

class Solution {
public:
    char toHexChar(int num)
    {
        if (num < 10)
            return '0' + num;
        else
            return 'a' + (num - 10);
        return '0';
    }

    string toHex(int num) {
        bool flag = false;
        string ret = "";
        for (int i = 28; i >= 0; i -= 4)
        {
            int dec = 0xF & (num>>i);
            if (flag || i == 0)
            {
                ret += toHexChar(dec);
            }
            else if (dec != 0)
            {
                flag = true;
                ret += toHexChar(dec);
            }
        }
        return ret;
    }
};

int main()
{
    int num = 0;
    Solution s = Solution();
    cout << s.toHex(num) << endl;
}
