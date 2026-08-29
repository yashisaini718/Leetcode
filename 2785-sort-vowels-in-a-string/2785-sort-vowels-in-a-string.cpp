class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        
        //vector<char>vowels;

        vector<int>frq(128,0);

        string v = "AEIOUaeiou";

        for(int i = 0 ; i < n ; i++ ){
            if(v.find(s[i]) != string::npos){
                //vowels.push_back(s[i]);
                frq[s[i]]++;
            }
        }

        //sort(vowels.begin(),vowels.end());

        int j = 0;

        for(int i = 0 ; i <n ; i++ ){
            if(v.find(s[i]) != string::npos){
                while(frq[v[j]] == 0) j++;
                //s[i] = vowels[j++];
                s[i] = v[j];
                frq[v[j]]--;
            }
        }

        return s;
    }
};