class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]) {
                //sorted first half
                if(nums[low] <= target && nums[mid] >= target){
                    // target maybe in sorted half
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if (nums[mid] <= nums[high]) {
                //sorted second half
                if(nums[mid] <= target && nums[high] >= target){
                    // target maybe in sorted second half
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        if(low < 0 || low >= n) return -1;
        else if(nums[low] != target) return -1;
        return low;
    }
};