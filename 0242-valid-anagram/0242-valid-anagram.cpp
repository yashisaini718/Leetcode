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
        // approach 2: count characters in both strings TC: O(n)
        int m1[26];
        int m2[26];
        for(char ch : s) m1[ch-'a']++;
        for(char ch : t) m2[ch-'a']++;
        for(char ch : s){
            if (m1[ch-'a'] != m2[ch-'a']) return false;
        }
        return true;
    }
};