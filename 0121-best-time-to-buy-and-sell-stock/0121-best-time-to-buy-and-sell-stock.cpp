class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize minPrice with the maximum possible integer value
        int maxProfit = 0; // Initialize maxProfit as 0

        for (int i = 0; i < prices.size(); i++) {
            // If the current price is less than the minPrice, update minPrice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
            // Calculate the profit if the current price is sold after buying at minPrice
            else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};
