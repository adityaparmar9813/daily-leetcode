class Solution {
   public:
	bool uniformArray(vector<int>& nums1) {
		int xmin = 1e9, cntOdd = 0;

		for (int x : nums1) {
			cntOdd += x & 1;
			xmin = min(xmin, x);
		}

		return xmin & 1 || cntOdd == 0;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)