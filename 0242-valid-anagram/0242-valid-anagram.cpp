class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        // approach 1: sort both and compare : TC O(nlogn)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // int i = 0, j = 0;
        // while( i < s.length() && j < t.length()){
        //     if (s[i] != t[j]) return false;
        //     i++;
        //     j++;
        // }
        // return true;
        // if (s == t) return true;
        // return false;

        map<char,int>m1;
        map<char,int>m2;
        for(char ch : s) m1[ch]++;
        for(char ch : t) m2[ch]++;
        for(char ch : s){
            if (m1[ch] != m2[ch]) return false;
        }
        return true;
    }
};