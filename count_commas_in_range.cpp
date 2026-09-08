class Solution {
   public:
	int countCommas(int n) {
		int m = n - 999;
		return m < 0 ? 0 : m;
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)