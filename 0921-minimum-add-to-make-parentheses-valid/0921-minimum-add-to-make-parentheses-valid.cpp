class Solution {
public:
    int minAddToMakeValid(string s) {
        //stack<char>stk;
        int open = 0;
        int cnt = 0;
        for(char c : s) {
            if (c == '('){
                open++;
            }
            else if (c == ')'){
                open--;
                if(open < 0) {
                    cnt++;
                    open++;
                }
            }
        }
        return open+cnt;
    }
};