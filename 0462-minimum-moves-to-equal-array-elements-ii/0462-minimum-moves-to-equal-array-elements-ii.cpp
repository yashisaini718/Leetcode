class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long t = nums[n/2];
        
        long long dis = 0;
        for(int i = 0 ; i < n ; i ++) {
            dis += abs(t - nums[i]);
        }
        return dis;
    }
};