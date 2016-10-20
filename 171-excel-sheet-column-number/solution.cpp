#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            num = num * 26 + (s[i] - 'A' + 1);
        }
        return num;
    }
};

int main()
{
    string str = "ZZ";
    Solution s = Solution();
    cout << s.titleToNumber(str) << endl;
}
