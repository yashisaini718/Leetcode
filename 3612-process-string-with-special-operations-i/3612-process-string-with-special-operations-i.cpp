class Solution {
public:
    string processStr(string s) {
        string result="";
        for( char ch : s){
            if( ch >= 'a' && ch <= 'z'){
                result+=ch;
            }
            else if (ch == '*'){
                int n=result.length();
                if(n > 0) result= result.substr(0,n-1);
            }
            else if (ch == '#'){
                string temp=result;
                result = result + temp;
            }
            else if (ch == '%'){
                reverse(begin(result),end(result));
            }
        }
        return result;
    }
};