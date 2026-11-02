class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long t;
        if(n & 1) t = nums[n/2];
        else {
            long long n1 = nums[n/2 - 1];
            long long n2 = nums[n/2];
            t = (n1 + n2) / 2;
        }
        
        long long dis = 0;
        for(int i = 0 ; i < n ; i ++) {
            dis += abs(t - nums[i]);
        }
        return dis;
    }
};