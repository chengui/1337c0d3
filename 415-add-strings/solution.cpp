#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int len1 = num1.length();
        int len2 = num2.length();
        int len = 1 + (len1 > len2 ? len1 : len2);
        string num(len, '0');
        while (len1 > 0 || len2 > 0)
        {
            int calc = num[len-1] - '0';
            if (len1 > 0)
                calc += num1[len1-1] - '0';
            if (len2 > 0)
                calc += num2[len2-1] - '0';
            num[len-1] = calc % 10 + '0';
            num[len-2] = calc / 10 + '0';
            len1--, len2--, len--;
        }
        if (num[0] == '0')
            num.erase(0, 1);
        return num;
    }
};

int main()
{
    string num1 = "9", num2= "99";
    Solution s = Solution();
    cout << s.addStrings(num1, num2) << endl;
}
