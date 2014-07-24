#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        string word, reverse;
        for (int i = 0; i < len; i++) {
            //keep a single word
            if (!isspace(s[i])) {
                word += s[i];
                continue;
            }
            //form the word to reversed string if counter space
            if (!word.empty()) {
                reverse = word + ' ' + reverse;
                word.clear();
            }
        }
        //count the last word
        if (!word.empty()) {
            reverse = word + ' ' + reverse;
            word.clear();
        }
        //save the result back
        s = reverse.substr(0, reverse.length() - 1);
    }
};

int main() {
    string s = "the see of blue";
    Solution solu = Solution();
    solu.reverseWords(s);
    cout << s << endl;
}
