class Solution {
public:
// TOP-RIGHT of rec1 should be greater than BOTTOM-LEFT of rec2
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if ((rec1[2] > rec2[0] && rec1[0] < rec2[2]) && (rec1[3] > rec2[1] && rec1[1] < rec2[3]))return true;
        return false;
    }
};