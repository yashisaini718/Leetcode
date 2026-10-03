class Solution {
    using ll = long long;
    
    ll hrs(vector<int>& piles, int m) {
        ll hr = 0;
        for(int pile : piles) {
            if(pile % m == 0) hr += pile/m;
            else hr += (pile/m) + 1;
        }
        return hr;
    }
    ll minBanana(vector<int>& piles, int h) {
        int n = piles.size();
        ll sum = 0;
        for( int pile : piles) {
            sum += pile;
        }
        ll l = 1;
        ll r = sum;
        ll ans = sum;
        while(l <= r) {
            ll m = l + (r - l) / 2;
            if(hrs(piles,m) <= h) {
                ans = min (ans,m);
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return minBanana(piles, h);
    }
};