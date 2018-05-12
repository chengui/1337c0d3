#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool compareCount(int S[256], int T[256]) {
        for (int i = 0; i < 256; i++) {
            if (S[i] < T[i])
                return false;
        }
        return true;
    }

    string minWindow(string S, string T) {
        int window = 0;
        int start = 0;
        int end = 0;
        int index = 0;

        int Tcount[256] = {0};
        int Scount[256] = {0};

        if (S.length() == 0 || S.length() < T.length())
            return "";

        for (int i = 0; i < T.length(); i++)
            Tcount[T[i]]++;
        for (int i = 0; i < T.length(); i++)
            Scount[S[i]]++;

        start = 0;
        end = T.length() - 1;
        while (start < S.length() && end < S.length()) {
            if (window != 0 && window <= T.length())
                break;
            int ret = compareCount(Scount, Tcount);
            if (ret) {
                index = start;
                window = end - start + 1;
                Scount[S[start]]--;
                start++;
            } else {
                if (window != 0) {
                    Scount[S[start]]--;
                    start++;
                }
                end++;
                Scount[S[end]]++;
            }
        }
        if (window == 0)
            return "";
        return S.substr(index, window);
    }
};

int main() {
    string S = "ADOBECODEBANC", T = "ABC";
    Solution solu = Solution();
    cout << solu.minWindow(S, T) << endl;
}

