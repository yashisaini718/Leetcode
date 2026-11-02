class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,long long>mpp;
        for(int i = 0 ; i < n ; i ++) {
            mpp.insert({nums[i],0});
        }
        for(auto &it : mpp) {
            int t = it.first;
            long long sum = 0;
            for(int i = 0 ; i < n ; i ++ ){
                sum += abs(nums[i]-t);
            }
            mpp[t] = sum;
        }

        long long great = LONG_MAX;
        for(int i = 0 ; i < n ; i ++) {
            if(mpp[nums[i]] < great) great = mpp[nums[i]];
        }
        return (int)great;
    }
};