class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        vector<int> hash(3,-1);
        for(int i=0;i<n;i++){
            hash[s[i]-'a']=i;
            //cnt = lastindex-firstindex+1
            //first index will always be zero hence cnt = lastindex + 1 
            // and min shows the lastindex that should be present for the substring to have all three characters
            cnt+=(1+min(hash[0],min(hash[1],hash[2])));
        }
        return cnt;
    }
};