class Solution {
    // subtracting a odd no. from any number switches its parity
    // hence finding smallest odd to keep constraaint for nums1[i] - nums1[j] >= 1

    bool makeOdd(vector<int>& nums1, int minOdd){
        for(int ele : nums1){
            if((ele & 1) == 0){
                if((ele - minOdd) < 1) return false;
            }
        }
        return true;
    }

    bool makeEven(vector<int>& nums1, int minOdd){
        for(int ele : nums1){
            if((ele & 1) != 0){
                if((ele - minOdd) < 1) return false;
            }
        }
        return true;
    }

public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        vector<int>odd;
        vector<int>even;

        for(int i = 0; i < n; i++){
            if ( nums1[i] & 1){
                odd.push_back(nums1[i]);
            }
            else {
                even.push_back(nums1[i]);
            }
        }

        // all are already even or odd
        if (odd.size() == n || even.size() == n) return true;

        // get the smallest odd number
        int minOdd = *min_element(odd.begin(),odd.end());

        // try to find if can be made all even or all odd
        if (makeOdd(nums1, minOdd)) return true;
        else if (makeEven(nums1, minOdd)) return true;

        // not possible 
        return false;
    }
};