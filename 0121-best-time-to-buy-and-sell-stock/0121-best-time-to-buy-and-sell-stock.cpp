class Solution {
public:
    // TC: O(N) SC: O(N)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_cost = prices[0];
        int max_profit=0;
        vector<int>profits(n,0);
        for (int i=1; i<n; i++){
            if ((prices[i] - min_cost) > 0) {
                profits[i] = prices[i] - min_cost;
            }
            if( min_cost > prices[i]) min_cost = prices[i];
        }
        int maxi = *max_element(profits.begin(), profits.end());
        return maxi;
    }
};