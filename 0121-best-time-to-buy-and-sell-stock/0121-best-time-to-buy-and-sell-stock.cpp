class Solution {
public:
    // TC: O(N) SC: O(N)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int min_cost = prices[0];
        int max_profit = 0;

        for (int i=1; i<n; i++){
            int profit = prices[i] - min_cost;

            max_profit= max(max_profit, profit);

            if (min_cost > prices[i]) min_cost = prices[i];
        }
        
        return max_profit;
    }
};