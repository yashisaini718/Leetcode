class Solution {
public:
    int reverse(int x) {
        int result=0;
        int max=INT_MAX/10;
        while(x!=0){
            if(abs(result)>max){
                return 0;
            }
            int d=x%10;
            result=result*10+d;
            x=x/10;
        }
        return result;
    }
};