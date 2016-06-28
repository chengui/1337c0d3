#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tmp = 0, res = 0, last = 0;
        map<char, int> index;
        for (int i = 0; i < s.length(); i++) {
            if (index.count(s[i]) <= 0) {
                index[s[i]] = i;
                tmp++;
            } else {
                if (index[s[i]] > last)
                    last = index[s[i]];
                tmp = i-last;
                index[s[i]] = i;
            }
            if (tmp > res) {
                res = tmp;
            }
        }
        return res;      
    }
};

int main()
{
    string str = "abcabcbb";
    Solution s = Solution();
    printf("%d\n", s.lengthOfLongestSubstring(str));
}
