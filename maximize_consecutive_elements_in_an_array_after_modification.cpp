class Solution {
   public:
	int maxSelectedElements(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int best = 1, keep = 1, bump = 1, last = -10;

		for (int x : nums) {
			switch (x - last) {
				case 0:
					bump = keep + 1;
					break;
				case 1:
					++keep;
					++bump;
					break;
				case 2:
					keep = bump + 1;
					bump = 1;
					break;
				default:
					keep = bump = 1;
			}

			best = max({best, keep, bump}), last = x;
		}

		return best;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)