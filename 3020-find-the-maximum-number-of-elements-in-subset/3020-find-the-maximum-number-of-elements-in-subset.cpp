class Solution {
 // increase the chain in simulated manner for the peak the frequency should be 1 else it should be atleast 2 to continue so making a map to keep count of frequency then for each element in the map checking if it's power is present in the map or not and since it would be int put a check to power not to be greater than LLONG_MAX/power 

 // then while finding the power in the map keep on increasing the chain if frequency is greater than equal 2 else calculate the maxLen since peak is reached

// if next power is not found means the powers are present in frequencies of 2 or more hence calculating maxLen as 2*k-1 else 2*k+1

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