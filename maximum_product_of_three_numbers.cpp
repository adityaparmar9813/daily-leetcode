class Solution {
   public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int n = nums.size();
		vector<int> possible;

		for (int i = 0; i < min(3, n); i++) {
			possible.push_back(nums[i]);
		}

		for (int i = max(3, n - 3); i < n; i++) {
			possible.push_back(nums[i]);
		}

		long long ans = LLONG_MIN;
		int m = possible.size();

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
					ans =
					    max(ans, 1LL * possible[i] * possible[j] * possible[k]);
				}
			}
		}

		return static_cast<int>(ans);
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)