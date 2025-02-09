class Solution {
   public:
	long long countBadPairs(vector<int>& nums) {
		unordered_map<int, int> mp;
		int n = nums.size();
		long long good = 0;

		for (int i = 0; i < nums.size(); i++) {
			mp[i - nums[i]]++;
		}

		for (const auto& [num, count] : mp) {
			good += (count * 1ll * (count - 1)) / 2;
		}

		return (n * 1ll * (n - 1) / 2) - good;
	}
};