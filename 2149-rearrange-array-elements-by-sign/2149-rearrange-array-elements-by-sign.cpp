class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        int odd_ind=1;
        int even_ind=0;
        for(int i=0; i<n; i++){
            if ( nums[i] < 0){
                result[odd_ind]= nums[i];
                odd_ind+=2;
            } 
            else{
                result[even_ind]= nums[i];
                even_ind+=2;
            }
        }
        return result;
    }
};