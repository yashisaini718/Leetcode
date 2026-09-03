class Solution {
    // bool checkDistinct(string str){
        
    //     for(char c : str){
    //         characters[c]++;
    //     }
    //     for(auto &it : characters){
    //         if(it.second >1) return false;
    //     }
    //     return true;
    // }

public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int maxi = 0;

        unordered_map<char,pair<int,int>>characters;

        int i = 0, j=0;

        while(i < n && j < n){
            if(characters.find(s[j]) != characters.end()){
                while(i <= characters[s[j]].second){
                    characters.erase(s[i]);
                    i++;
                }
            }
            
            characters[s[j]].first++;
            characters[s[j]].second = j;
            maxi = max(maxi, (j-i+1));
            j++;
        }

        return maxi;
    }
};