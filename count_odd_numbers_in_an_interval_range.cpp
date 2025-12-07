class Solution {
   public:
	int countOdds(int low, int high) {
		return (high - low) / 2 + (low % 2 != 0 || high % 2 != 0);
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)