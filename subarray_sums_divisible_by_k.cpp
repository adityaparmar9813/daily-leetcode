class Solution {
public:
    static int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        int prefix = 0, result = 0;
        count[0] = 1;

        for (int x: nums) {
            prefix = (prefix + x) % k;
            if (prefix < 0) prefix += k;
            count[prefix]++;
        }

        for (int x: count) {
            result += x * (x - 1) / 2;
        }
        return result;
    }
};


// Time Complexity : O(n)
// Space Complexity : O(k)
