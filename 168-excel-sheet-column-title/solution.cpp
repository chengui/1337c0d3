#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string title;
        while (n > 0) {
            if (n % 26) {
                title.append(1, 'A' - 1 + n % 26);
            } else {
                title.append(1, 'Z');
                n = n - 26;
            }
            n = n / 26;
        }
        return string(title.rbegin(), title.rend());
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.convertToTitle(1) << endl;
    cout << solu.convertToTitle(2) << endl;
    cout << solu.convertToTitle(26) << endl;
    cout << solu.convertToTitle(27) << endl;
    cout << solu.convertToTitle(52) << endl;
    cout << solu.convertToTitle(26*26+26) << endl;
}
