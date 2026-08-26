class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit(0);

        for(int buy(0); buy < prices.size(); buy++)
        {

            for (int sell(buy + 1); sell < prices.size(); sell++) {
                int profit = prices[sell] - prices[buy];
                max_profit = (max_profit < profit) ? profit : max_profit;
            }
        }

        return max_profit;
    }
};
