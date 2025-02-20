class Solution {
    string res;
    bool buildNum(unordered_set<string>&number,string &curr,int n){
        if(curr.size()==n){
            if(number.count(curr)==0){
                res=curr;
                return true;
            }
            return false;
        }
        curr.push_back('0');
        if(buildNum(number,curr,n)) return true;
        curr.pop_back();
        curr.push_back('1');
        if(buildNum(number,curr,n)) return true;
        curr.pop_back();
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>number(nums.begin(),nums.end());
        string curr="";
        buildNum(number,curr,n);
        return res;
    }
};