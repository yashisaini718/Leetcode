class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<int>st;
        string result = "";
        int start=0;
        for(int i = 0 ; i < n ; i ++) {
            if(s[i] == '(') {
                if(st.empty()) start = i;
                st.push(i);
            }
            else if( s[i] == ')') {
                st.pop();
                if (st.empty()) {
                    for (int j = start + 1 ; j < i ; j ++ ) {
                        result.push_back(s[j]);
                    }
                }
            }
        }
        return result;
    }
};