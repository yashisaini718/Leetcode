class Solution {
public:
// NEED TO FIND largest number whose square is less than equal to x
    int mySqrt(int n) {
        if (n == 1 || n == 0) return n;
        int low = 2;
        int high = n/2;
        int ans = 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid <= n/mid){
                ans = max(ans,mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};