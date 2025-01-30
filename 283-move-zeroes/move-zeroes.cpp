class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
        for(int i=ind+1;i<n;i++){
           if(nums[i]!=0){
                nums[ind]=nums[i];
                ind++;
           } 
        }
        for(int i=ind;i<n;i++){
            nums[i]=0;
        }
        }
        
    }
};