class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0; // available bracket
        int cnt = 0; // required bracket
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