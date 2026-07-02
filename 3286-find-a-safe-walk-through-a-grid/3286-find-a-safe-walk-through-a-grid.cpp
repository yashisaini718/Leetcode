class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m= grid.size();
        int n= grid[0].size();

        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));

        // the cost of first cell is given by the value of gridd[0][0]
        distance[0][0]=grid[0][0];

        vector<int>da={0,1,0,-1};
        vector<int>db={1,0,-1,0};

        // initialising a min_heap of tuple
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq;
        pq.push({distance[0][0],0,0});

        while(!pq.empty()){
            auto [dist,di,dj]=pq.top();
            pq.pop();

            // a shorter distance is already stored in the matrix
            if(dist>distance[di][dj]) continue;

            for(int k=0;k<4;k++){
                int ni=di+da[k];
                int nj=dj+db[k];
                // new distance will be the weight of (di,dj) + cost of reaching the new node

                if(ni>=0 && ni<m && nj>=0 && nj<n && dist+grid[ni][nj] < distance[ni][nj] ){
                    distance[ni][nj]=dist+grid[ni][nj];
                    pq.push({dist+grid[ni][nj],ni,nj});
                }

            }
            
        }
        return distance[m-1][n-1]<health;
    }
};