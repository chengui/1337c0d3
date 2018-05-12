#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        while (*s && *s == ' ') s++;
        if (!*s) return false;
        if (*s == '-' || *s == '+') s++;
        const char *t = s;
        while (*t && *t != 'e' && *t != ' ') t++;
        if (*t == 'e') {
            if (t == s) return false;
            char *p = new char[t-s];
            strncpy(p, s, t-s);
            p[t-s] = '\0';
            t++;
            if (*t == '-' || *t == '+') t++;
            if (!*t || *t == ' ') return false;
            while (*t && *t != ' ' && *t >= '0' && *t <= '9') t++;
            while (*t && *t == ' ') t++;
            if (*t) return false;
            return isNumber(p);
        } else {
            while (*t && *t == ' ') t++;
            if (*t) return false;
            bool dot = false, num = false;
            while (*s && *s != ' ')
                if (*s >= '0' && *s <= '9')
                    num = true, s++;
                else if (*s == '.' && !dot)
                    dot = true, s++;
                else
                    return false;
            if (dot && !num) return false;
            return true;
        }
    }
};

int main() {
    Solution solu = Solution();
    const char *s = "13";
    cout << solu.isNumber(s) << endl;
}
