class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int t = nums[n/2];
        int dis = 0;
        for(int i = 0 ; i < n ; i ++) {
            dis += abs(t - nums[i]);
        }
        return dis;
    }
};