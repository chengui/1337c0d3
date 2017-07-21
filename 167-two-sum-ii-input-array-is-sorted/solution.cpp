#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> hash;
        for (size_t i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i+1;
        }
        for (int i = 0; i < (int)numbers.size(); i++) {
            if (hash.count(target-numbers[i])) {
                int A[] = {i+1, hash[target-numbers[i]]};
                return vector<int>(A, A + 2);
            }
        }
        return vector<int>();
    }
};

int main() {
    int A[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> numbers(A, A+sizeof(A)/sizeof(int));
    Solution solu = Solution();
    vector<int> res = solu.twoSum(numbers, target);
    cout << res[0] << ", " << res[1] << endl;
}
