class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int cnt=0;
        int maxi=0;
        for (auto it : st){
            int curr= it;
            if (st.find(curr-1) != st.end()){
                continue;
            }
            cnt=1;
            while(st.find(curr+1) != st.end()){
                cnt++;
                curr++;
                maxi=max(maxi,cnt);
            }
        }
        maxi=max(cnt, maxi);

        return maxi;
    }
};