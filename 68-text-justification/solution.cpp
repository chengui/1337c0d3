#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string justify(vector<string> &words, int L, int len, int st, int ed) {
        string ret, str_space;
        int spaces = 0, extra = 0;
        if (st == ed) {
            spaces = L - len;
        } else {
            spaces = (L - len) / (ed - st);
            extra = (L - len) % (ed - st);
        }
        for (int i = st; i <= ed; i++) {
            if (i == ed && i != st)
                str_space = "";
            else if (i - st < extra)
                str_space.assign(spaces+1, ' ');
            else
                str_space.assign(spaces, ' ');

            ret += words[i] + str_space;
        }

        return ret;
    }

    string left_justify(vector<string> &words, int L, int len, int st, int ed) {
        string ret, str_space;
        int spaces = L - len;
        for (int i = st; i < ed; i++) {
            str_space.assign(1, ' ');
            spaces--;
            ret += words[i] + str_space;
        }
        str_space.assign(spaces, ' ');
        ret += words[ed] + str_space;
        return ret;
    }

    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        string str;
        int n = words.size(), len = 0;
        int spaces = 0, start = 0, end = 0;
        if (n == 0) return ret;
        for (int i = 0; i < n; i++) {
            len += words[i].size();
            spaces = i - start;
            if (len + spaces <= L) {
                end = i;
            } else {
                str = justify(words, L, len-words[i].size(), start, end);
                ret.push_back(str);
                len = words[i].size();
                start = end = i;
            }
        }
        str = left_justify(words, L, len, start, end);
        ret.push_back(str);

        return ret;
    }
};

int main() {
    Solution solu = Solution();
    vector<string> words = {"this", "is", "an", "example", "of", "text", "justification"};
    vector<string> output = solu.fullJustify(words, 16);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}
