class Solution {
   public:
	int minimumRecolors(string blocks, int k) {
		int whiteCount = 0;

		for (int i = 0; i < k; i++) {
			whiteCount += blocks[i] == 'W';
		}

		int ans = whiteCount;

		for (int i = k; i < blocks.size(); i++) {
			whiteCount -= blocks[i - k] == 'W';
			whiteCount += blocks[i] == 'W';

			ans = min(ans, whiteCount);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)