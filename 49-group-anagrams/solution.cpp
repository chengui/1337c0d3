#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        vector<int> idx;
        map<string, vector<int> > hash;
        map<string, vector<int> >::iterator iter;
        string tmp;

        for (int i = 0; i < strs.size(); i++) {
            string tmp(strs[i]);
            idx.clear();
            idx.resize(1, i);
            sort(tmp.begin(), tmp.end());
            if (hash.count(tmp) > 0)
                hash[tmp].push_back(i);
            else
                hash[tmp] = idx;
        }
        for (iter = hash.begin(); iter != hash.end(); iter++) {
            idx = iter->second;
            if (idx.size() <= 1) continue;
            for (int i = 0; i < idx.size(); i++)
                res.push_back(strs[idx[i]]);
        }
        return res;
    }
};

int main() {
    const char *A[] = {
        "tea","and","ate","eat","den"
    };
    vector<string> strs(A, A + 6);
    Solution solu = Solution();
    vector<string> res = solu.anagrams(strs);
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}
