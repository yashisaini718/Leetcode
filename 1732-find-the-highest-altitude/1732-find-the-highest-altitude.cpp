class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
        vector<int>altitude(n+1,INT_MIN);
        altitude[0]=0;
        for(int i=0;i<n;i++){
            altitude[i+1]=altitude[i]+gain[i];
        }
        return *max_element(begin(altitude),end(altitude));
    }
};