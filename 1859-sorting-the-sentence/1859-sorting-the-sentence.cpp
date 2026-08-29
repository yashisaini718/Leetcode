class Solution {
public:
    string sortSentence(string s) {
        vector<string>sentence(10,"");
        int i = 0;
        string temp = "";
        while ( i < s.length()){
            if(isdigit(s[i])){
                sentence[s[i]-'0'] = temp;
                temp = "";
            }
            if (s[i] != ' ' && !isdigit(s[i])){
                temp.push_back(s[i]);
            }
            i++;
        }
        string result = "";
        for(int i=1; i<=9; i++){
            if (sentence[i] != ""){
                result = result + sentence[i] + " ";
            }
        }
        result.pop_back();
        return result;
    }
};