#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
    int romanToInt(string s) {
        int sum = 0;
        size_t len = s.length();
        map<char, int> dict;
        dict['I'] = 1, dict['V'] = 5, dict['X'] = 10, dict['L'] = 50;
        dict['C'] = 100, dict['D'] = 500, dict['M'] = 1000;
        for (size_t i = 0; i < len; i++)
        {
            if ((i == len - 1) || dict[s[i]] >= dict[s[i+1]])
                sum += dict[s[i]];
            else
                sum -= dict[s[i]];
        }
        return sum;
    }
};

int main()
{
    string str = "IL";
    Solution s = Solution();
    cout << s.romanToInt(str) << endl;
}
