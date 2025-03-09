class Solution {
   public:
	int numberOfAlternatingGroups(vector<int>& colors, int k) {
		int n = colors.size(), len = 1, ans = 0;

		for (int i = 1; i < n + k - 1; i++) {
			if (colors[i % n] != colors[(i + 1) % n]) {
				len++;
			} else {
				len = 1;
			}

			ans += (len >= k);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)