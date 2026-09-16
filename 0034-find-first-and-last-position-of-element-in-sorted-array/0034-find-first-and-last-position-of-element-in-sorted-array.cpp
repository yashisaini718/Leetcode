class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lower_bound(nums.begin(), nums.end(), target) - (nums.begin());
        if (first  == n) return {-1,-1};
        int last = upper_bound(nums.begin(),nums.end(), target) - nums.begin();
        if ((first == last) && (nums[first] == target)) return {first,first};
        else if (nums[first] == target && nums[last-1] == target) return {first,last-1};
        else return {-1,-1};
        
    }
};