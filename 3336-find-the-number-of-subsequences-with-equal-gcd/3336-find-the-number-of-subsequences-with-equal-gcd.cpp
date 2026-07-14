class Solution {
    int Mod = 1000000007;
    int t[201][201][201];
    // for each element 3 choices : take in seq1 , take in seq2, skip
    int solve(vector<int>& nums,int i, int first, int second){
        if(i == nums.size()){
            bool emptysequence = (first == 0 && second == 0)?1:0;
            bool equalgcd = (first == second)?1:0;
            if(!emptysequence && equalgcd) return 1;
            return 0;
        }
        if (t[i][first][second] != -1) return t[i][first][second];

        int skip= solve(nums, i+1, first, second);
        int take1= solve(nums, i+1, __gcd(first,nums[i]),second);
        int take2= solve(nums, i+1, first, __gcd(second,nums[i]));
        return t[i][first][second]= (0LL + skip + take1 + take2) % Mod ;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums,0,0,0);
    }
};