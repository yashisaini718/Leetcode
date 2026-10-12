class Solution {
   typedef long long ll;
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        ll cnt = 0;
        unordered_map<ll,ll> mpp;
        mpp[0] = 1;
        ll cum_Xor = 0;
        for (char &c : word) {
            int shift = (c - 'a');
            cum_Xor ^= (1 << shift);

            cnt += mpp[cum_Xor];

            for(char ch = 'a' ; ch <= 'j' ; ch ++) {
                int shift = (ch - 'a');
                int check_Xor = cum_Xor ^ (1<<shift);
                cnt += mpp[check_Xor];
            }

            mpp[cum_Xor]++;
        }
        return cnt;
        
    }
};