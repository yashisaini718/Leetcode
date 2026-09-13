class Solution {

    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffset, int colOffset){
        int n = A.size();
        int cnt = 0;
        for(int i = 0; i < n ;i ++){
            for(int j = 0; j < n; j++){
                int x = i + rowOffset;
                int y = j + colOffset;
                if( x >= 0 && x < n && y >= 0 && y < n){
                    if(A[i][j] == 1 && A[i][j] == B[x][y]) cnt++;
                }
            }
        }
        return cnt;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxi = 0;
        for(int i = -n+1 ; i <= n-1 ; i++){
            for(int  j = -n+1 ; j <= n-1 ; j++){
                maxi = max(maxi, countOverlap(img1, img2, i, j));
            }
        }
        return maxi;
    }
};