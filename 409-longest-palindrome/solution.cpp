#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int upper[26] = {0}, lower[26] = {0};
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                lower[s[i]-'a']++;
            else
                upper[s[i]-'A']++;
        }
        int cnt = 0, flag = 0;
        for (size_t i = 0; i < 26; i++)
        {
            cout << 'A' + i << ": " << upper[i] << endl;
            cout << 'a' + i << ": " << lower[i] << endl;
            if (upper[i] % 2 == 1 || lower[i] % 2 == 1)
                flag = 1;
            cnt += upper[i] / 2 + lower[i] / 2;
        }
        cnt *= 2;
        if (flag == 1)
            cnt += 1;
        return cnt;
    }
};

int main()
{
    string str = "abccccdd";
    Solution s = Solution();
    cout  << s.longestPalindrome(str) << endl;
}
