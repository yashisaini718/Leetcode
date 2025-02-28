class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int num2=target-nums[i];
            if(mpp.find(num2)!=mpp.end()){
                ans={i,mpp[num2]};
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return {};
    }    
};