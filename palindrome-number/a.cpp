#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        if (x < 0)
            return false;

        //always keep x larger than y to do half travesal
        do {
            y = 10 * y + x % 10; //append last digit from x
            if (y >= x) //check symmetry from middle digit
                break;
            x = x / 10; //remove last digit of x
        } while (y < x && 0 < y); //check symmetry from middle line

        return x == y;
    }
};

int main() {
    int x = 131000;
    Solution solu = Solution();
    cout << solu.isPalindrome(x) << endl;
}
