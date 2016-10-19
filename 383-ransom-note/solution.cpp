#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count1[26] = {0}, count2[26] = {0};
        for (size_t i = 0; i < ransomNote.length(); i++)
        {
            count1[ransomNote[i] - 'a']++;
        }
        for (size_t i = 0; i < magazine.length(); i++)
        {
            count2[magazine[i] - 'a']++;
        }
        for (size_t i = 0; i < 26; i++)
        {
            if (count1[i] > count2[i])
                return false;
        }
        return true;
    }
};

int main()
{
    string ransomNote = "aa", magazine = "aab";
    Solution s = Solution();
    cout << s.canConstruct(ransomNote, magazine) << endl;
}
