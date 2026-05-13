class Solution {
   public:
	int minMoves(vector<int>& nums, int limit) {
		int n = nums.size();
		vector<int> diff(2 * limit + 2, 0);

		for (int i = 0; i < n / 2; i++) {
			int a = min(nums[i], nums[n - 1 - i]);
			int b = max(nums[i], nums[n - 1 - i]);

			diff[a + 1] -= 1;
			diff[b + limit + 1] += 1;

			diff[a + b] -= 1;
			diff[a + b + 1] += 1;
		}

		int pairs = n / 2;
		int current = pairs * 2;
		int answer = INT_MAX;

		for (int sum = 2; sum <= 2 * limit; sum++) {
			current += diff[sum];
			answer = min(answer, current);
		}

		return answer;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)