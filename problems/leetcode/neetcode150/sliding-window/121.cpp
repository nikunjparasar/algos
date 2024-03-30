#include "include.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_price = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            buy_price = min(buy_price, prices[i]);
            max_profit = max(max_profit, prices[i]-buy_price);
        }
        return max_profit;
    }
};