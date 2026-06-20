class Solution {
    // first thought : build the entire array then use left pass to calculate effect of left building and right pass to calculate effect of right building but not possible because constraints are larger (10^9)

    // but the restrictions array traversal possible (10^5) hence use left and right pass to restrict the height of restricted building then use the formula to get the max height between two buildings with height and id
    
    typedef long long ll;
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});

        sort(begin(restrictions),end(restrictions));
        for(int i=1; i<restrictions.size(); i++){
            restrictions[i][1]=min(restrictions[i][1],
            restrictions[i-1][1]+
            (restrictions[i][0]-restrictions[i-1][0]));
        }
        for(int i=restrictions.size()-2;i>=0;i--){
            restrictions[i][1]=min(restrictions[i][1],
            restrictions[i+1][1]+
            (restrictions[i+1][0]-restrictions[i][0]));
        }
        int ans=0;

        for(int i=1;i<restrictions.size();i++){
            ll h1=restrictions[i-1][1];
            ll h2=restrictions[i][1];
            ll d= restrictions[i][0]-restrictions[i-1][0];
            ans= max(ans, (int)(d+h1+h2)/2);
        }
        return ans;
    }
};