class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        for(char c : word){
            freq[c]++;
        }
        vector<pair<int,char>>keys;
        for( auto & it : freq){
            keys.push_back({it.second,it.first});
        }
        sort(keys.rbegin(),keys.rend());
        int ans=0;
        int cnt=0;
        for(auto it : keys){
            cnt++;
            if(cnt<=8){
                ans+=(it.first);
            }
            else if(cnt>8 && cnt<=16){
                ans+=(it.first*2);
            }
            else if(cnt>16 && cnt<=24){
                ans+=(it.first*3);
            }
            else{
                ans+=(it.first*4);
            }
        }
        return ans;
    }
};