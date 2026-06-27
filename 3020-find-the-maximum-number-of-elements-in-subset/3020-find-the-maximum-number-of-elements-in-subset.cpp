class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mpp;
        for(int num : nums){
           mpp[num]++;
        }
        int maxLen=1;
        if(mpp.find(1)!=mpp.end()){
            maxLen=max(maxLen, (mpp[1]%2==0)?mpp[1]-1:mpp[1]);
        }
        for(auto &it : mpp){
            int num= it.first;
            if(num == 1) continue;
            long long power=num;
            int k=0;
            while (mpp.find(power)!= mpp.end()){
                if(mpp[power]>=2){
                    k++;
                    if(power>LLONG_MAX/power){
                        break;
                    }
                    power=power*power;
                }
                else{
                    maxLen=max(maxLen,2*k+1);
                    break;
                }
            }
            if(mpp.find(power) == mpp.end()){
                maxLen=max(maxLen,2*k-1);
            }
        }
        return maxLen;
    }
};