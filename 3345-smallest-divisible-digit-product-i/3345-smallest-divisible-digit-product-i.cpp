class Solution {
    int getDigitProduct(int n){
        int product = 1;
        while(n > 0){
            int d = n % 10;
            if (d == 0) return 0;
            product *= d;
            n = n/10;
        }
        return product;
    }
public:
    int smallestNumber(int n, int t) {
        for( int i=n; i<=100; i++){
            int pro = getDigitProduct(i);
            if (pro % t == 0) return i;
        }
        return 0;
    }
};