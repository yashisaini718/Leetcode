class Solution {
public:
    bool backtrack(int ind,vector<bool> &used,vector<int> &seq,int n){
        while(ind<seq.size() && seq[ind]!=0) ind++;
        if(ind==seq.size()) return true;
        for(int i=n;i>=1;i--){
            if(used[i]) continue;
            if(i==1){
                seq[ind]=i;
                used[i]=true;
                if(backtrack(ind+1,used,seq,n)) return true;
                seq[ind]=0;
                used[i]=false;
            }
            else if(ind+i<seq.size() && seq[ind+i]==0){
                seq[ind]=i;
                seq[ind+i]=i;
                used[i]=true;
                if(backtrack(ind+1,used,seq,n)) return true;
                seq[ind]=0;
                seq[ind+i]=0;
                used[i]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<bool> used(n+1,false);
        vector<int> seq(2*n-1,0);
        backtrack(0,used,seq,n);
        return seq;
    }
};