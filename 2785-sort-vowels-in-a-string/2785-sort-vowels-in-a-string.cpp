class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char>vowels;
        string v = "AEIOUaeiou";
        for(int i = 0 ; i < n ; i++ ){
            if(v.find(s[i]) != string::npos){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int j = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(v.find(s[i]) != string::npos){
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};