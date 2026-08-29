class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char>vowels;
        for(int i = 0 ; i < n ; i++ ){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int j = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};