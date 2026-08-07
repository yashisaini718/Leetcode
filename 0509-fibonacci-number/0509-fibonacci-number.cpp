class Solution {
    int t[32];
    int solve(int n){
        if (n == 0) return t[n] = 0;
        if (n == 1) return t[n] = 1;
        if (t[n] != -1) return t[n];
        return t[n]= solve(n-1) + solve(n-2);
    }
public:
    int fib(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};