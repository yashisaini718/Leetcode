class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        // instead of building the whole result string build the length of the result
        long long L= 0;
        for(char &ch : s){
            if(ch == '%'){
                continue;
            } else if (ch == '*'){
                if (L >= 1) L--;
            } else if (ch == '#'){
                L*=2;
            } else {
                L++;
            }
        }

        if (k >= L) return '.';
        
        // backtrack each of the operation to map the required character in the result to a character in s
        for(int i= n-1; i>=0; i--) {
            if (s[i] == '#'){
                L= L/2;
                k= (k >= L)? k-L: k;
            }
            else if (s[i] == '%'){
                // no change in L
                k= L-k-1;
            }
            else if (s[i] == '*'){
                L++;
                // no change in k
            }
            else{//letter
                L--;
                // no change in k
            }
            // after doing all these check if L==k 
            if(L == k) return s[i];
        }
        return '.';
    }

};