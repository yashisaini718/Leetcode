class Solution {
    //            USE MODIFIED KADANE 
    // In standard Kadane we use to set to zero if negative occurs but in this since the array could have all negative numbers and we need to return the largest negative in that case we should get the sum via comparison with nums[i] instead of zero
public:
    int maxSubArray(vector<int>& nums) {
        // if sum becomes negative use sum=0
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i=0; i<n; i++) {
            //sum += nums[i];
            sum=max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};