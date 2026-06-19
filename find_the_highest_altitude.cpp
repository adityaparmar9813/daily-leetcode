class Solution {
   public:
	int largestAltitude(vector<int>& gain) {
		int height = 0, ans = 0;

		for (int g : gain) {
			height += g;
			ans = max(ans, height);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)