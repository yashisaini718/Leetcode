class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>>roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"},{400, "CD"}, {100, "C"},{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string ans = "";

        // int n = nums.size();
        // int i = 0;

        // while(num > 0){
        //     auto &d = roman[i];
        //     while(num >= d.first){
        //         int q = num / d.first;
        //         int r = num % d.first;
        //         while(q--) ans += d.second;
        //         num = r;
        //     } 
        //     i++;
        // }

        for(auto &[value, symbol] : roman){
            while(num >= value){
                ans += symbol;
                num -= value;
            }
        }
        return ans;     
    }
};