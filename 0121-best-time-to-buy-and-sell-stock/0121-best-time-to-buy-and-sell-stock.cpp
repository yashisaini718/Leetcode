class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> min_price(n,0);
        vector<int> max_price(n,0);
        int maxi = 0;
        min_price[0]=prices[0];
        max_price[n-1]=prices[n-1];
        for (int i=1; i<n; i++) {
            min_price[i] = min(prices[i], min_price[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            max_price[i] = max(prices[i], max_price[i+1]);
        }
        int i = 0, j = n-1;
        for (int i=0; i <n-1; i++) {
            int profit = max_price[i+1] - min_price[i];
            maxi = max(profit, maxi);
        }
        return maxi;
    }
};