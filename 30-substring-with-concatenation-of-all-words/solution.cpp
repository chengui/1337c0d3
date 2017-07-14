#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        int ssize = S.size();
        int lsize = L.size();
        if (lsize == 0) return res;
        int m = L[0].size(), beg = 0, len = 0;
        map<string, int> dict, cnt;
        string tmp;

        for (int i = 0; i < lsize; i++)
            if (dict.count(L[i]) > 0)
                dict[L[i]]++;
            else
                dict[L[i]] = 1;

        for (int i = 0; i < m; i++) {
            len = 0;
            beg = i;
            for (int j = 0; i + j < ssize; j+=m) {
                string word = S.substr(i+j, m);
                if (dict.count(word) <= 0) {
                    cnt.clear();
                    beg = i + j + m;
                    len = 0;
                } else {
                    if (cnt.count(word) <= 0)
                        cnt[word] = 1;
                    else
                        cnt[word]++;
                    len++;
                }
                if (cnt[word] > dict[word]) {
                    do {
                        tmp = S.substr(beg, m);
                        cnt[tmp]--;
                        beg += m;
                        len--;
                    } while (tmp != word);
                }
                if (len == lsize) {
                    res.push_back(beg);
                    cnt[S.substr(beg, m)]--;
                    beg += m;
                    len--;
                }
            }
            cnt.clear();
        }
        return res;
    }
};

int main() {
    const char* A[] = {"foo", "bar"};
    string S = "barfoothefoobarman";
    vector<string> L(A, A+2);
    Solution solu = Solution();
    vector<int> res = solu.findSubstring(S, L);
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}
