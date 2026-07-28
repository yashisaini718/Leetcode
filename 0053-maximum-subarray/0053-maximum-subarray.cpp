class Solution {
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