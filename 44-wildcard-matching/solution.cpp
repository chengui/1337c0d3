#include <iostream>

using namespace std;

class Solution {
public:
    bool matchstar(const char *s, const char *p) {
        while (*p == '*' && *p)p++;
        if (*p == '\0') return true;
        do {
            const char *ss = s, *pp = p;
            while (*ss && *pp && (*ss == *pp || *pp == '?')) ss++,pp++;
            if (*ss == '\0' && *pp == '\0') return true;
            if (*pp == '*') return isMatch(ss, pp);
            if (*ss == '\0') return false;
            s++;
        } while (*s);
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0') return true;
        if (*s != '\0' && (*s == *p || *p == '?')) return isMatch(s+1, p+1);
        if (*p == '*') return matchstar(s, p+1);
        return false;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.isMatch("aa", "a") << endl;
    cout << solu.isMatch("aa", "aa") << endl;
    cout << solu.isMatch("aaa", "aa") << endl;
    cout << solu.isMatch("ab", "?*") << endl;
    cout << solu.isMatch("aab", "c*a*b") << endl;
}
