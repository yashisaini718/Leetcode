class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;
        vector<int> nums(arr);
        sort(nums.begin(), nums.end());
        int rank = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                rank++;
            }
            mpp[nums[i]] = rank;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};