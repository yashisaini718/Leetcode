class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x==0){
            return true;
        }
        long long y=0 ;
        long long n=x;
        while(x!=0){
            int d=x%10;
            y=y*10+d;
            x=x/10;
        }
        if(y==n){
            return true;
        }
        else{
            return false;
        }
    }
};