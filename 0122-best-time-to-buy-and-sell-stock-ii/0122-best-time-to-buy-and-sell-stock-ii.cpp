class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // If the price on the next day is higher, sell and count the profit
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        
        return maxProfit;
    }
};
