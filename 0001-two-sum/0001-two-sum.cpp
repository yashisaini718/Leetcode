class Solution {
    //TC: if unordered_map ; O(N) if map ; O(NlogN)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // making a hash map to keep the counter of a val with it's index 
        // and as move forward check if target-nums[i] present in map or not 
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if (hash.count(req)){
                return {hash[req],i};
            }
            hash[nums[i]]=i;
        }
        return {};
    }
};