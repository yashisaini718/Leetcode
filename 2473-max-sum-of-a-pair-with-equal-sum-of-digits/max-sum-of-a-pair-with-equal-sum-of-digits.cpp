class Solution {
public:
    int Sum(int num){
        int sum=0;
        while(num>0){
            int d=num%10;
            sum+=d;
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,int> digitSum;
        int ans=-1;
        for(int i=0;i<n;i++){
            int curr=Sum(nums[i]);
            if(digitSum.find(curr)!=digitSum.end()){
                ans=max(ans,digitSum[curr]+nums[i]);
                digitSum[curr]=max(digitSum[curr],nums[i]);
            }
            else{
                digitSum[curr]=nums[i];
            }
        }
        return ans;
    }
};