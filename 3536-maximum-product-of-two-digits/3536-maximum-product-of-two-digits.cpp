class Solution {
public:
    int maxProduct(int n) {
        int largest=0;
        int second_largest=INT_MIN;
        vector<int>digits(10,0);
        int i=0;
        while(n>0){
            int d=n%10;
            digits[i++]=d;
            n=n/10;
        }
        sort(digits.begin(), digits.end());
        return digits[9]*digits[8];
    }
};