class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int need = 0;
        for(int num : nums) {
            need += (maxi-num);
        }
        return need;
    }
};