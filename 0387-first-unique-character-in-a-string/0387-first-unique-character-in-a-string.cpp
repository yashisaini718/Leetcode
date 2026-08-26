class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int hash[26];
        for(int i=0; i<n; i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a'] == 1) return i;
        }
        return -1;
        // unordered_map<char,pair<int,int>>mpp;
        // for(int i=n-1; i>=0; i--){
        //     mpp[s[i]].first++;
        //     mpp[s[i]].second = i;
        // }
        // for(auto &itr : mpp){
        //     if (itr.second.first == 1){
        //         return itr.second.second;
        //     }
        // }
        // return -1;
    }
};