class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str = "";
        int cnt = 0;
        int digit = sum / 9;
        int remain = sum % 9;
        for(int i = 0 ; i < digit ; i++){
            if(cnt == num) return "";
            str.push_back('9');
            cnt ++;
        }
        if(remain > 0){
            if (cnt == num) return "";
            str.push_back(remain + '0');
            cnt ++;
        }
        while(cnt < num){
            str.push_back('0');
            cnt++;
        }
        return str;
    }
};