class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int max_profit(0);

        // for(int buy(0); buy < prices.size(); buy++)
        // {
        //     for (int sell(buy + 1); sell < prices.size(); sell++) {
        //         int profit = prices[sell] - prices[buy];
        //         max_profit = (max_profit < profit) ? profit : max_profit;
        //     }
        // }

        // return max_profit;

        int max_profit(0);
        int min_buy_price = prices[0];

        for(int i(0); i < prices.size(); i++)
        {
            min_buy_price = std::min(min_buy_price, prices[i]);
            int profit = prices[i] - min_buy_price;
            max_profit = std::max(max_profit, profit);
        }

        return max_profit;

        
    }
};
