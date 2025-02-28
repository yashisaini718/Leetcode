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
        /*
        TC of loop approach: O(log10(x)) everytime the number is divided by x
        SC: O(1)
        string num= to_string(x);
        reverse(num.begin(),num.end());
        long long y=stoll(num);
        long long z=x;
        if(y==z) return true;
        else return false;
        TC of string based: O(log10(x))
        SC: O(n) n;length of string 
        hence loop approach is more optimized
        */
    }
};