class Solution {
    // optimal approach: 1. going from the end find the break point  2. find the first digit just greater than break point from the end 3. reverse the subarray just after break point
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int brk=-1;
       for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            brk=i;
            break;
        }
       }
       if (brk == -1) {
        sort(nums.begin(),nums.end());
        return ;
       }
       for(int i=n-1;i>=0;i--){
        if (nums[i] > nums[brk]){
            swap(nums[i],nums[brk]);
            reverse(nums.begin()+brk+1, nums.end());
            return;
        }
       }
        return;
    }
};