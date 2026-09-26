class Solution {
    bool checkThreshold(vector<int> &arr, int ele, int threshold) {
        int sum = 0;
        for( int num : arr) {
            if(num % ele == 0) sum += (num/ele);
            else sum += ((num/ele)+1);
        }
        if(sum <= threshold) {
            return true;
        }
        return false;

    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(checkThreshold(nums, mid, threshold)){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};