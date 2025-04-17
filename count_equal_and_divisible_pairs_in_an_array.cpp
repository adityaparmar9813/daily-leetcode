class Solution {
   public:
	int countPairs(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> mp;
		int ans = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (const auto index : mp[nums[i]]) {
				if ((index * i) % k == 0) {
					ans++;
				}
			}

			mp[nums[i]].push_back(i);
		}

		return ans;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)