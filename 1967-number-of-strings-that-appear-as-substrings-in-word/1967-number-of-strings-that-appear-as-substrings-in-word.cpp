class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>freq;
        for(string str : patterns){
            freq[str]++;
        }
        int cnt=0;
        for(int i=0;i<word.length();i++){
            string s="";
            for(int j=i;j<word.length();j++){
                s+=word[j];
                if(freq.find(s) != freq.end()){
                    cnt+=freq[s];
                    freq.erase(s);
                }
            }
        }
        return cnt;

        // int cnt=0;
        // for(string p:patterns)
        // {
        //     if(word.find(p)!=string::npos)
        //     {
        //         cnt++;
        //     }

        // }
        // return cnt;
    }
};