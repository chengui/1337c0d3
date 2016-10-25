#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int max = 0, min = 0;
        int profit = 0, maxprofit = 0;
        max = min = prices[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (prices[i] > max)
            {
                max = min = prices[i];
            }
            else if (prices[i] < min)
            {
                min = prices[i];
                profit = max - min;
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
};

int main()
{
    int tmp[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(tmp, tmp+sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.maxProfit(prices) << endl;
}
