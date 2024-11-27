class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int crr=target-nums[i];
            if(hash.find(crr)!=hash.end()){
                return {hash[crr],i};
            }
            hash[nums[i]]=i;
        }
        return{};
        
    }
};