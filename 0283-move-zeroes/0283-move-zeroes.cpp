class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                idx=i;
                break;
            }
        }
        if(idx == -1) return;
        for(int j=idx;j<n;j++){
            if(nums[j] != 0){
                swap(nums[j],nums[idx]);
                if(idx<n-1)idx++;
            }
        }
    }
};