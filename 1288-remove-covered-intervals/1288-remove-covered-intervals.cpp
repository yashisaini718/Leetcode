class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(begin(intervals),end(intervals));
        for(int i=0;i<n;i++){
            if(ans.size() == 0 || intervals[i][1] > ans.back()[1] && intervals[i][0] > ans.back()[0]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][1] > ans.back()[1] && intervals[i][0] <= ans.back()[0]){
                ans.back()[0]=intervals[i][0];
                ans.back()[1]=intervals[i][1];
            }
            else if(intervals[i][1]<=ans.back()[1]) continue;
        }
        return ans.size();
    }
};