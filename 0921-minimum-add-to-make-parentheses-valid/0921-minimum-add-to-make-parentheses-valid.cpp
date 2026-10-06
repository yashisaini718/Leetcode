class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int cnt = 0;
        for(char c : s) {
            if (c == '('){
                stk.push(c);
            }
            else if (c == ')'){
                if (!stk.empty()) stk.pop();
                else {
                    cnt++;
                }
            }
        }
        if(!stk.empty()){
            while(!stk.empty()) {
                cnt++;
                stk.pop();
            }
        }
        return cnt;
    }
};