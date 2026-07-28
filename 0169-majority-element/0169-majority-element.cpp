class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int candidate = -1;
        int count = 0;
        for (int i=0; i<n; i++){
            if (count == 0) {
                candidate= nums[i]; 
                count= 1;
            }
            else if (nums[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        int cnt= 0;
        for(int i=0; i<n; i++) {
            if (nums[i] == candidate) {
                cnt++;
            }
        }
        if (cnt > n/2) return candidate;
        return -1;
    }
};