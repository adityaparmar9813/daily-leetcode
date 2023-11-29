class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i=0; i < 32; i++) count += (n & (1<<i)) == 0 ? 0 : 1; 
        return count;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)