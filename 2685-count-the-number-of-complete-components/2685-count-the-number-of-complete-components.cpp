class Solution {
    pair<int,int> traversal(int node, map<int,vector<int>>&adj, vector<int>&vis){
        vis[node]=1;
        int nodes=1;
        int edges=adj[node].size();
        for( auto &nbr : adj[node]){
            if(!vis[nbr]){
                auto[sub_nodes,sub_edges]=traversal(nbr,adj,vis);
                nodes+=sub_nodes;
                edges+=sub_edges;
            }
        }
        return {nodes,edges};
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cc=0;
        vector<int>vis(n+1,0);
        // int nodes,edges;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                auto[nodes,edges]=traversal(i, adj, vis);
                if(edges/2 == nodes*(nodes-1)/2) cc++; 
            }
        }
        return cc;
    }
};