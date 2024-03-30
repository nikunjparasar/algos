#include "include.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = INT_MAX;
        int profit = INT_MIN;
        for(int i = 0; i < n; i++){
            buy_price = min(buy_price, prices[i]);
            profit = max(profit, prices[i] - buy_price);
        }
        return profit;
    }
};