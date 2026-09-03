class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int maxi = 0;
        // no need to store count of elemnts
        unordered_map<char,int>characters;

        int i = 0, j=0;

        while(i < n && j < n){

            if(characters.find(s[j]) != characters.end()){
                while(i <= characters[s[j]]){
                    characters.erase(s[i]);
                    i++;
                }
            }

            characters[s[j]] = j;
            maxi = max(maxi, (j-i+1));
            j++;
        }

        return maxi;
    }
};