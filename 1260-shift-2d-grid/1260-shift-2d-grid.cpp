class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>gridrow(m*n,0);
        int l=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                gridrow[l++]=grid[i][j];
            }
        }
        int len=gridrow.size();
        k= k% len;
        reverse(gridrow.begin(),gridrow.begin()+len-k);
        reverse(gridrow.begin()+len-k,gridrow.end());
        reverse(gridrow.begin(),gridrow.end());
        l=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=gridrow[l++];
            }
        }
        return grid;
    }
};