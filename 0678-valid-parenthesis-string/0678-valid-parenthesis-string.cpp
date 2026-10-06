class Solution {
public:
    bool checkValidString(string s) {
        stack <int> stk; // open brackets

        stack <int> choice; // can use asterik for any open or close

        for(int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                stk.push(i);
            }

            else if (s[i] == ')') {

                if (!stk.empty()) stk.pop(); // have a corresponding open bracket

                else if(!choice.empty() && (choice.top() < i)) { 
                    // need to use 1 asterik as open bracket
                    choice.pop();
                }

                else return false;
            }

            else { // if * encountered
                choice.push(i);
            }
        }

        if(!stk.empty()) { 
            // if all open brackets don't have corresponding close brackets

            while(!stk.empty() && !choice.empty() && stk.top() < choice.top()){
                stk.pop();
                choice.pop(); 
                // each open corresponds to one close either via asterik or clear close bracket
            }
        }

        if(stk.empty()) return true; // all corresponding exists
        
        return false;
    }
};