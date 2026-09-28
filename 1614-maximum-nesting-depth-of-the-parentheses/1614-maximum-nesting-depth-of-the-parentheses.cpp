class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi = 0;
        for(char c : s) {
            if (c == '(') {
                st.push(c);
                int l =  st.size();
                maxi = max(maxi,l);
            }
            else if (c == ')') {
                st.pop();
            }
        }
        return maxi;

    }
};