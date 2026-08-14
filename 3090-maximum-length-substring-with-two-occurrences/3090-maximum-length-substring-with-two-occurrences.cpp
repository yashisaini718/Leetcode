class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            array<int, 26> count{};
            for (int j = i; j < n; j++) {
                int ind = s[j] - 'a';
                count[ind]++;
                if (count[ind] > 2) {
                    break;
                }
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};