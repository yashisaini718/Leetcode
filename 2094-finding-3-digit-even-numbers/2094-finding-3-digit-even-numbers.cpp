class Solution {
    void solve(int count, int num, vector<bool>& used, vector<int>& digits, set<int>& results){
        if (count == 3){
            results.insert(num);
            return;
        }
        for(int k=0; k<digits.size(); k++){
            if (used[k]) continue;
            if (count == 0 && digits[k] == 0) continue;
            if (count == 2 && digits[k] % 2 != 0) continue;
            used[k] = true;
            solve(count+1, num*10+digits[k], used, digits, results);
            used[k] = false;
        }
    }
    public:
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(),false);
        set<int> results;
        solve(0, 0, used, digits, results);
        return vector<int>(results.begin(), results.end());
    }
};