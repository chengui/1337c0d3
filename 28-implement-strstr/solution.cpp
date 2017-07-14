#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);
        int i = 0, j = 0, k = 0, ptr = 0;
        int *nextval = new int[m];
        nextval[0] = -1;
        for (j = 1; j < m; j++) {
            ptr = nextval[j-1];
            while (ptr >= 0 && needle[ptr+1] != needle[j])
                ptr = nextval[ptr];
            if (needle[ptr+1] == needle[j])
                nextval[j] = ptr + 1;
            else
                nextval[j] = -1;
        }
        i = 0, j = 0;
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                j++;
                i++;
            } else if (j== 0){
                i++;
            } else {
                j=nextval[j-1]+1;
            }
        }
        if (j == m)
            return haystack + i-j;
        return NULL;
    }
};

int main() {
    const char *haystack = "helloworld";
    const char *needle = "owo";
    Solution solu = Solution();
    cout << solu.strStr((char *)haystack, (char *)needle) << endl;
}
