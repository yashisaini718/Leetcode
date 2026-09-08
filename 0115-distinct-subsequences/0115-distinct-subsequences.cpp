class Solution {
    vector<vector<int>> dt;
    int solve(string &s, string &t, int i, int j){
        if (j == t.length()) return dt[i][j] = 1;
        if (i == s.length()) return dt[i][j] = 0;

        if (dt[i][j] != -1) return dt[i][j];

        if(s[i] == t[j]){
            int take = solve(s,t,i+1,j+1);
            int nottake = solve(s,t,i+1,j);
            return dt[i][j] = take+nottake;
        }
        return dt[i][j] = solve(s,t,i+1,j);
    }
public:
    int numDistinct(string s, string t) {
        dt.resize(1002,vector<int>(1002,-1));
        return solve(s,t,0,0);
    }
};