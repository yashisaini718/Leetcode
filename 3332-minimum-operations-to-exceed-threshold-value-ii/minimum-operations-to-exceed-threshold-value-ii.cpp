class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<long long>ms(nums.begin(),nums.end());
        int cnt=0;
        while(*ms.begin()<k){
            auto it1=ms.begin();
            auto it2=next(it1);
            if(it2==ms.end()) break;
            long long newNum=min(*it1,*it2)*2+max(*it1,*it2);
            ms.erase(it1);
            ms.erase(it2);
            ms.insert(newNum);
            cnt++;
        }
        return cnt;
    }
};