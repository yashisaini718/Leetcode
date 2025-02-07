class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=queries.size();
        map<int,int>ballmap;
        map<int,int>colormap;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(ballmap.find(ball)!=ballmap.end()){
                colormap[ballmap[ball]]--;
                if(colormap[ballmap[ball]]==0){
                    colormap.erase(ballmap[ball]);
                }
            }
            ballmap[ball]=color;
            colormap[ballmap[ball]]++;
            ans.push_back(colormap.size());
        }
        return ans;
    }
};