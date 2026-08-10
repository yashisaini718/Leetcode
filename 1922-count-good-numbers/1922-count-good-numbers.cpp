class Solution {
    long long MOD = 1000000007;
    long long power(int x, long long n, int ans){
        if (n == 0) return ans;
        if (n % 2 == 0) {
            return power((x*1LL*x)%MOD, n/2, ans);
        }
        ans = (ans *1LL* x) % MOD;
        return power(x, n-1, ans);
    }
public:
    int countGoodNumbers(long long n) {
        int result = 1;
        
        if (n % 2 == 0){
            int ans=1;
            result = (power(5,n/2,ans) * 1LL * power(4,n/2, ans)) % MOD;
        } 
        else{
            int ans=1;
            result = (power(5,(n/2)+1,ans) * 1LL * power(4,n/2,ans)) % MOD;
        }
        return result % MOD;
    }
};