class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
        return ceil(log(buckets) / log(totalTime / poisonTime + 1));
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)