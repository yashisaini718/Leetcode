class Solution {
public:
    // check for parity of index where two same digits arrive like odd-even places or even-odd places check parity in start if after mid parity changes means single element already arrived else still not arrived


// example dry run nums = [1,1,2,3,3,4,4,8,8]
    bool checkParityChange(int mid, vector<int>& nums) {

        // mid points index 4 now nums[mid] == nums[mid-1] == 3 but mid is not odd so first if false secondly nums[mid] == nums[mid + 1] condition false and hence parity changed means single element is in first half

        if(nums[mid] == nums[mid - 1] && mid % 2 != 0) return false;
        else if (nums[mid] == nums[mid + 1] && mid % 2 == 0) return false;
        return true;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        bool evenodd = false;

        if (n == 1) return nums[0];

        if(nums[0] == nums[1]) evenodd = true;
        else return nums[0];

        int ans = -1;
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            if(checkParityChange(mid,nums)){
                ans = nums[mid];
                high = mid - 1;
            } 
            else{
                low =  mid + 1;
            }
        }

        return ans;
    }
};