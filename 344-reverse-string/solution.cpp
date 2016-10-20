#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        size_t len = s.length();
        for (size_t i = 0; i < len / 2; i++)
        {
            char tmp = s[i];
            s[i] = s[len-1 - i];
            s[len-1 - i] = tmp;
        }
        return s;
    }
};

int main()
{
    string str = "hello";
    Solution s = Solution();
    cout << s.reverseString(str) << endl;
}
