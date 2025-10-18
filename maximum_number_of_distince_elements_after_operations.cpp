class Solution {
   public:
	int maxDistinctElements(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int res = 0;
		long long prev = LLONG_MIN;

		for (int i : nums) {
			if (prev < i - k) {
				prev = i - k;
				res++;
			} else if (prev < i + k) {
				prev = prev + 1;
				res++;
			}
		}

		return res;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)