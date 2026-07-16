class Solution {
public:
    int hammingWeight(int n) {
        return bitset<32>(n).count();
        // the count function of bitset works as same as __builtin_popcount
        // this creates a bitset of 32 size for the number n 
        // and count gives the count of set bits in bitset of n
    }
};