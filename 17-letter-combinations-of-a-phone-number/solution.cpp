#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res, tmp;
        vector<string> dict;
        int len = digits.length();
        int chr = digits[len - 1] - '0';
        if (len == 0) {
            res.push_back(string(""));
            return res;
        }

        dict.push_back(string(1, ' '));
        dict.push_back(string(""));
        dict.push_back(string("abc"));
        dict.push_back(string("def"));
        dict.push_back(string("ghi"));
        dict.push_back(string("jkl"));
        dict.push_back(string("mno"));
        dict.push_back(string("pqrs"));
        dict.push_back(string("tuv"));
        dict.push_back(string("wxyz"));
        if (len == 1) {
            for (int j = 0; j < dict[chr].length(); j++) {
                string tmpstr(1, dict[chr].at(j));
                res.push_back(tmpstr);
            }
            return res;
        }

        string subdigits = digits.substr(0, len - 1);
        tmp = letterCombinations(subdigits);

        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < dict[chr].length(); j++) {
                string tmpstr(tmp[i]);
                tmpstr += dict[chr][j];
                res.push_back(tmpstr);
            }
        }
        return res;

    }
};

int main() {
    string digits = "23";
    Solution solu = Solution();
    vector<string> res = solu.letterCombinations(digits);
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}
