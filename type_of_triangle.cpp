class Solution {
   public:
	string triangleType(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int a = nums[0], b = nums[1], c = nums[2];

		if (a == b && b == c) {
			return "equilateral";
		}
		if (a + b <= c) {
			return "none";
		}
		if (a == b || b == c || a == c) {
			return "isosceles";
		}
		return "scalene";
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)