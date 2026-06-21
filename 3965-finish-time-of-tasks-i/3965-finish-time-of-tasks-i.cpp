class Solution {
    typedef long long ll;
    ll dfs(ll node, unordered_map<ll,vector<ll>>&Tree, vector<int>&baseTime, vector<ll>&finishTime){
        if(Tree.find(node) == Tree.end()){
            finishTime[node]=baseTime[node];
            return finishTime[node];
        }
        ll minTime=LLONG_MAX;
        ll maxTime=LLONG_MIN;
        for(ll child : Tree[node]){
            ll childfinish=dfs(child,Tree,baseTime,finishTime);
            minTime=min(minTime,childfinish);
            maxTime=max(maxTime,childfinish);
        }
        finishTime[node]= 2 * maxTime - minTime + baseTime[node];
        return finishTime[node];
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<ll,vector<ll>>Tree;
        vector<ll>finishTime(n,0);
        for(auto &node : edges){
            Tree[node[0]].push_back(node[1]);
        }
        return dfs (0, Tree, baseTime, finishTime);
    }
};