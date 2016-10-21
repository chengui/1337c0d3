#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        char cnt1[26] = {0}, cnt2[26] = {0};
        for (size_t i = 0; i < s.length(); i++)
            cnt1[s[i]-'a']++;
        for (size_t i = 0; i < t.length(); i++)
            cnt2[t[i]-'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt1[i] != cnt2[i])
                return false;
        return true;
    }
};

int main()
{
    // string s1 = "anagram", s2 = "nagaram";
    string s1 = "rat", s2 = "car";
    Solution s = Solution();
    cout << s.isAnagram(s1, s2) << endl;
}
