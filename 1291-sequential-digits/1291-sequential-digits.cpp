class Solution {
    void solve(int i,int num, int low, int high, vector<int>&ans){
        if(i > 9) return;
        if(num > high) return;
        if(num >= low) ans.push_back(num);
        num=num*10+i+1;
        solve(i+1, num, low, high, ans);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,i,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};