#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> once;
        map<char, int> more;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (more.count(s[i]))
            {
                more[s[i]]++;
                continue;
            }
            if (once.count(s[i]))
            {
                once.erase(s[i]);
                more[s[i]] = 1;
            }
            else
            {
                once[s[i]] = i;
            }
        }
        int ret = s.length();
        for (map<char, int>::iterator it = once.begin(); it != once.end(); it++)
        {
            if (it->second < ret)
                ret = it->second;
        }
        if (ret == (int)s.length())
            return -1;
        return ret;
    }
};

int main()
{
    // string str = "leetcode";
    // string str = "loveleetcode";
    string str = "aabbcc";
    Solution s = Solution();
    cout << s.firstUniqChar(str) << endl;
}
