class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven=0;
        int sumOdd=0;
        for(int i=1;i<2*n;i+=2){
            sumOdd+=i;
            sumEven+=i+1;
        }
        return __gcd(sumEven,sumOdd);
    }
};