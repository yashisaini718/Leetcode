class Solution {
public:
    int majorityElement(vector <int> & nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int cnt = 1 ;
        for(int i = 0 ; i < n-1 ; i++ ) {
            if ( cnt > n/2 ) return nums[i] ; 
            if ( nums[i] != nums[i+1] ) {
                cnt=1 ; 
                continue;
            }
            cnt++ ;
        }
        if( cnt > n/2) return nums[n-1] ;
        return -1 ;
    }
};