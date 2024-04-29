class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<20> x(0);

        for(int num: nums) {
            x ^= num;
        }
        x ^= k;
 
        return x.count();
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
