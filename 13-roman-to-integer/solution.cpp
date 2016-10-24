#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanCharToInt(char c)
    {
        switch (c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {

        int top = 0, sum = 0;
        int len = s.length();

        for (int i = len-1; i >= 0; i--)
        {
            int num = romanCharToInt(s[i]);
            if (num < top)
                sum -= num;
            else
                sum += num;
            top = num;
        }
        return sum;
    }
};

int main()
{
    string str = "MCMLXX";
    Solution s = Solution();
    cout << s.romanToInt(str) << endl;
}
