class Solution {
    int helper(int n, int i, int sign, string &s, long long ans){
        if ( i >= n || !isdigit(s[i])){
            return max(INT_MIN, min(INT_MAX, int(ans*sign)));
        }
        ans = ans * 10 + (s[i] - '0');
        if(ans*sign > INT_MAX) return INT_MAX;
        if(ans*sign < INT_MIN) return INT_MIN;
        return helper(n, i+1, sign, s, ans);
    }
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while (s[i] == ' ') i++;
        long long ans = 0;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '-')?-1:1;
            i++;
        }
        return helper(n, i, sign, s, ans);
    }
};