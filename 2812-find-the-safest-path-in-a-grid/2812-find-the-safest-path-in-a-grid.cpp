class Solution {
    // multi-source BFS
    // dijkstra like approach using priority queue
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    visited[i][j]=1;
                    distance[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int>da={0,1,0,-1};
        vector<int>db={1,0,-1,0};

        while(q.size() != 0){
            auto it = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni=it.first+da[k];
                int nj=it.second+db[k];

                if(ni>=0 && nj>=0 && ni<n && nj<n && visited[ni][nj]==0 && distance[ni][nj]>distance[it.first][it.second]+1){
                    distance[ni][nj]=distance[it.first][it.second]+1;
                    visited[ni][nj]=1;
                    q.push({ni,nj});
                }
            }    
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        priority_queue<vector<int>>pq;
        // priority queue will stoore the max safeness till now, curr x, curr y
        pq.push(vector<int>{distance[0][0],0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            // if valid path found it will return answer here
            if(curr[1] ==n-1 && curr[2]==n-1) return curr[0];

            for(int k=0;k<4;k++){
                int di=curr[1]+da[k];
                int dj=curr[2]+db[k];
                if(di>=0 && dj>=0 && di<n && dj<n && visited[di][dj]!=1){
                    pq.push(vector<int>{min(curr[0],distance[di][dj]),di,dj});
                    visited[di][dj]=1;
                }
            }
        }

        // else return -1
        return -1;
    }
};