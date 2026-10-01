class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for( auto ch : s ) {
            if (ch == '(' || ch == '[' || ch == '{') st.push(ch);

            else if (ch == ')'){
                if (st.size() != 0 && st.top() == '(') st.pop();
                else return false;
            }

            else if (ch == ']') {
                if (st.size() != 0 && st.top() == '[') st.pop();
                else return false;
            }

            else {
                if (st.size() != 0 && st.top() == '{') st.pop();
                else return false;
            }

        }

        if (st.size() == 0) return true; 
        
        return false;
    }
};