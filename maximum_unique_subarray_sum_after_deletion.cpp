class Solution {
   public:
	int maxSum(vector<int>& nums) {
		vector<bool> mp(201, false);
		int ans = 0;

		for (int num : nums) {
			if (mp[num + 100] != false || num <= 0) {
				continue;
			}
			ans += num;
			mp[num + 100] = true;
		}

		return ans == 0 ? *max_element(nums.begin(), nums.end()) : ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)