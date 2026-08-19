class Solution {
    int countSeat(const vector<int> &reserved_cols){
        int maxi = 0;
        vector<int>seats(11,0);
        for(int it : reserved_cols){
            seats[it]=1;
        }
        if (seats[2] == 0 && seats[3] == 0 && seats[4] == 0 && seats[5] == 0){
            if(seats[6] == 0 && seats[7] == 0 && seats[8] == 0 && seats[9] == 0){
                maxi = 2;
            }
            else maxi = 1;
        } 
        else{
            if(seats[4] == 0 && seats[5] == 0 && seats[6] == 0 && seats[7] == 0){
                maxi = 1;
            }
            else if(seats[6] == 0 && seats[7] == 0 && seats[8] == 0 && seats[9] == 0){
                maxi = 1;
            }
        }
        return maxi;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int totalCount = 0;
        map<int,vector<int>>mpp;
        for(int i=0; i<reservedSeats.size(); i++){
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];
            mpp[row].push_back(col);
        }
        for(auto & it : mpp){
            int i = it.first;
            totalCount += countSeat(it.second);
        }
        totalCount += (n-mpp.size())*(2);
        return totalCount;

    }
};