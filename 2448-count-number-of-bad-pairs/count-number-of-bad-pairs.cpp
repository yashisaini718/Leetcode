class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int>hash;
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=i-hash[nums[i]-i];
            hash[nums[i]-i]++;
        }
        return cnt;
    }
};