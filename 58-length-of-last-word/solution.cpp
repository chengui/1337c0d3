#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
       if (s == '\0')
           return 0;

       int i = 0;
       char buffer[2048] = {0};
       while (*s) {
           if (s[0] == ' ') {
               i = 0;
           } else {
               buffer[i] = s[0];
               i++;
               buffer[i] = '\0';
           }
           s++;
       }
       return strlen(buffer);
    }
};

int main() {
    const char *s = "Hello World";
    Solution solu = Solution();
    cout << solu.lengthOfLastWord(s) << endl;
}
