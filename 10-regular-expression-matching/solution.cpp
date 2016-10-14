#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool matchstar(int c, const char *s, const char *p)
    {
       do
       {
           if (isMatch(s, p)) return true;
       } while (*s != '\0' && (*s++ == c || c == '.'));
       return false;
    }

    bool isMatch(const char *s, const char *p)
    {
       if (*s == '\0' && *p == '\0') return true;
       if (*p && p[1] == '*') return matchstar(p[0], s, p+2);
       if (*s != '\0' && (p[0]=='.' || p[0]==*s)) return isMatch(s+1, p+1);
       return false;
    }

    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

};

int main()
{
    string t = "aa", p = ".*";
    Solution s = Solution();
    cout << s.isMatch(t, p) << endl;
}

