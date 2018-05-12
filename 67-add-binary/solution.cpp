#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0, j = 0;
        int f = 0, c = 0;
        string sum;

        i = a.length() - 1;
        j = b.length() - 1;
        for(; i >= 0 && j >= 0; i--, j--) {
            f = (a[i] - '0') + (b[j] - '0') + c;
            c = f / 2;
            f = f % 2;
            sum.insert(0, 1, f + '0');
        }

        for(; i >= 0; i--) {
            f = (a[i] - '0') + c;
            c = f / 2;
            f = f % 2;
            sum.insert(0, 1, f + '0');
        }

        for(; j >= 0; j--) {
            f = (b[j] - '0') + c;
            c = f / 2;
            f = f % 2;
            sum.insert(0, 1, f + '0');
        }

        if (c)
            sum.insert(0, 1, '1');
        return sum;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.addBinary("11", "1") << endl;
}
