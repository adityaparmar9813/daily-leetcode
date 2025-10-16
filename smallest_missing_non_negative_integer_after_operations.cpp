class Solution {
   public:
	int findSmallestInteger(vector<int>& nums, int value) {
		vector<int> count(value, 0);

		for (int num : nums) {
			int rem = ((num % value) + value) % value;
			count[rem]++;
		}

		int ans = 1e5;

		for (int i = 0; i < value; i++) {
			ans = min(ans, i + count[i] * value);
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(value)