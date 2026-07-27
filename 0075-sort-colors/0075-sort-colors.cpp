class Solution {
    // can use three pointers low, mid, high to keep track of numbers
    // like 0's would be from low, 1's would be from mid and 2's would be till high
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size() ;
        int low= 0, mid= 0, high= n-1 ;
        while (mid <= high) {
            if ( nums[mid] == 0 ){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if ( nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return ;
    }
};