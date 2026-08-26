class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,pair<int,int>>mpp;
        for(int i=n-1; i>=0; i--){
            mpp[s[i]].first++;
            mpp[s[i]].second = i;
        }
        for(auto &itr : mpp){
            if (itr.second.first == 1){
                return itr.second.second;
            }
        }
        return -1;
    }
};