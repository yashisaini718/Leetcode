class Solution {
    bool distinct(map<int,int>&freq){
        for(auto it:freq){
            if(it.second != 1) return false;
        }
        return true;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>freq;
        long long sum=0;
        long long maxi=0;
        // first window
        for(int i=0;i<k;i++){
            sum+=nums[i];
            freq[nums[i]]++;
        }
        if(freq.size() == k )maxi=max(maxi,sum);
        // i is moved via end of the window hence it shoudl go all the way to the end of the array
        for(int i=k;i<n;i++){
            freq[nums[i]]++;
            sum-=nums[i-k];
            sum+=nums[i];
            if(freq[nums[i-k]]==1)freq.erase(nums[i-k]);
            else freq[nums[i-k]]--;
            if(freq.size() == k) maxi=max(maxi,sum);
        }
        return maxi;
    }
};