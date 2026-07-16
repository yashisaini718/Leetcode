class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGcd(n,0);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>mx)mx=nums[i];
            prefixGcd[i]=__gcd(nums[i],mx);
        }
        sort(begin(prefixGcd),end(prefixGcd));
        long long sum=0;
        for(int i=0;i<n/2;i++){
            long long GCD=__gcd(prefixGcd[i],prefixGcd[n-1-i]);
            sum= sum + 0LL + GCD;
        }
        return sum;
    }
};