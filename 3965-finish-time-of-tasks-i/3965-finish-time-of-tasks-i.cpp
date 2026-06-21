class Solution {
    // making a Tree map to store tree nodes with its child
    // made a finishTime array to stre the time of each node
    // for each leafnode the finishtime is equal to baseTime
    // for each nonleaf node the finishtime can be calculated using a for loop and keeping track of min and max across the children to get the required finishTime of node 
    // remember to use long long for all tasks

    typedef long long ll;

    ll dfs(ll node, unordered_map<ll,vector<ll>>&Tree, vector<int>&baseTime, vector<ll>&finishTime){
        //basecase for leaf node
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

        // building the tree
        for(auto &node : edges){
            Tree[node[0]].push_back(node[1]);
        }
        
        return dfs (0, Tree, baseTime, finishTime);
    }
};