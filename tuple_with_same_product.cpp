class Solution {
   public:
	int tupleSameProduct(vector<int>& nums) {
		unordered_map<int, int> mp;
		int n = nums.size(), ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				mp[nums[i] * nums[j]]++;
			}
		}

		for (const auto& [num, count] : mp) {
			ans += count * (count - 1) * 4;
		}

		return ans;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)