#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> dict1, dict2;
        for (size_t i = 0; i < ransomNote.length(); i++)
        {
            if (dict1.count(ransomNote[i]))
                dict1[ransomNote[i]] ++;
            else
                dict1[ransomNote[i]] = 0;
        }
        for (size_t i = 0; i < magazine.length(); i++)
        {
            if (dict2.count(magazine[i]))
                dict2[magazine[i]] ++;
            else
                dict2[magazine[i]] = 0;
        }
        for (map<char, int>::iterator it = dict1.begin(); it != dict1.end(); it++)
        {
            if (!dict2.count(it->first) || dict2[it->first] < it->second)
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
