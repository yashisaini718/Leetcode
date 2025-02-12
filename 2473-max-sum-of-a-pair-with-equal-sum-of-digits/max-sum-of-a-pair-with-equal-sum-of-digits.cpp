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
        map<int,vector<int>> digitSum;
        int ans=-1;
        for(int i=0;i<n;i++){
            int curr=Sum(nums[i]);
            if(digitSum.find(curr)!=digitSum.end()){
                int sum=*max_element(digitSum[curr].begin(),digitSum[curr].end())+nums[i];
                ans=max(ans,sum);
            }
            digitSum[curr].push_back(nums[i]);
        }
        return ans;
    }
};