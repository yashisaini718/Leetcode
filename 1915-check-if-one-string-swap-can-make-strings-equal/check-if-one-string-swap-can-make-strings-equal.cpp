class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        vector<int> diff_index;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diff_index.push_back(i);
            }
        }
        if(diff_index.size()==0) return true;
        if(diff_index.size()==2){
            int i=diff_index[0],j=diff_index[1];
            swap(s1[i],s1[j]);
            if(s1==s2) return true;
            else return false;
        }
        else return false;
    }
};