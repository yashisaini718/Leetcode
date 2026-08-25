class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        int i=k;
        for(i; i<k*102; i+=k){
            if(mpp.find(i) == mpp.end()) return i;
        }
        return i;
    }
};