class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product=nums[i]*nums[j];
                hash[product]++;
            }
        }
        int cnt=0;
        for(auto it:hash){
            cnt+=(it.second*(it.second-1)/2)*8;
        }
        return cnt;
    }
};