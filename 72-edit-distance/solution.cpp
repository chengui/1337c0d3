#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) //add
            return word2.length();
        if (word2.length() == 0) //delete
            return word1.length();
        int idx = 0; //find the same prefix sequence
        for (;idx < word1.length() && idx < word2.length() && word1[idx] == word2[idx]; idx++);
        if (idx > 0)
            return minDistance(word1.substr(idx), word2.substr(idx));
        int tmp = 0, modify = max(word1.length(),  word2.length());
        for (int i = 0; i < word1.length(); i++) {
            int j = 0;
            j = word2.find_first_of(word1[i], 0);
            if (j == string::npos)
                continue;
            while (j != string::npos) {//find the same char
                tmp = max(i, j) + minDistance(word1.substr(i), word2.substr(j));
                if (tmp < modify)
                    modify = tmp;
                j = word2.find_first_of(word1[i], j+1);
            }
        }
        return modify;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.minDistance("horse", "ros") << endl;
}
