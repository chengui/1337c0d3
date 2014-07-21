#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int number = 0;  //integer value from string
        int flag = 1;  //flag int: 1 for positive, -1 for negative

        //strip white spaces
        while (*str == ' ')
            str++;

        //mark flag int: '+' to 1, '-' to -1
        if (*str == '-' || *str == '+') {
            flag = (*str=='-')?-1:1;
            str++;
        }

        //calculate number from string one by one
        while (*str) {
            if (!isdigit(*str))
                break;

            //check if exploited in tenths
            if (number > (INT_MAX - (*str - '0'))/10) {
                number = INT_MAX+1;
                break;
            }

            //add up the digit
            number = 10 * number + (*str - '0');
            str++;
        }

        //when exploited in tenths or digits, it's larger than INT_MAX,
        //so flag bit is set, if positive, get INT_MAX, else get INT_MIN
        if (number & (1<<31)) {
            number = number & (1<<31);  //constant here
            number = (flag==1)?number-1:number;
        }

        return number * flag;
    }
};

int main() {
    const char *str = "  -2147483647";
    Solution solu = Solution();
    cout << solu.atoi(str) <<endl;
}
