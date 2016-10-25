#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int profit = 0;
        int save_profit = 0;
        int buyprice = prices[0];
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (prices[i] <= buyprice)
                buyprice = prices[i];
            else
            {
                profit = prices[i] - buyprice;
                if (profit > save_profit)
                    save_profit = profit;
            }
        }
        return save_profit;
    }
};

int main()
{
    int tmp[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(tmp, tmp+sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.maxProfit(prices) << endl;
}
