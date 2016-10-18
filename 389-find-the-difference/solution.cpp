#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = '\0';
        for (size_t i = 0; i < s.length(); i++)
            r ^= s[i];
        for (size_t i = 0; i < t.length(); i++)
            r ^= t[i];
        return r;
    }
};

int main()
{
    string a = "abcd", b = "abcde";
    Solution s = Solution();
    cout << s.findTheDifference(a, b) << endl;
}
