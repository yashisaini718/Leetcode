class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        // approach 1: sort both and compare
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i = 0, j = 0;
        // while( i < s.length() && j < t.length()){
        //     if (s[i] != t[j]) return false;
        //     i++;
        //     j++;
        // }
        // return true;
        if (s == t) return true;
        return false;
    }
};