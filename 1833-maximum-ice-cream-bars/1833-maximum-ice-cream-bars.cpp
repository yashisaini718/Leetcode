class Solution {
    typedef long long ll;
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int maxi=*max_element(begin(costs),end(costs));
        vector<ll>cntArr(maxi+1,0);
        vector<int>ans(n,0);
        for(long long cost : costs){
            cntArr[cost]++;
        }
        for(long long i=1;i<cntArr.size();i++){
            cntArr[i]=cntArr[i]+cntArr[i-1];
        }
        for(int i=n-1;i>=0;i--){
            ans[cntArr[costs[i]]-1]=costs[i];
            cntArr[costs[i]]--;
        }
        int icecreams=0;
        int remainingCoins=coins;
        for(int bars : ans){
            if(bars<=remainingCoins){
                icecreams++;
                remainingCoins-=bars;
            }
        }
        return icecreams;
    }
};