class Solution {
   public:
	int countCompleteSubarrays(vector<int>& nums) {
		int i = 0, j = 0, ans = 0;
		set<int> st;
		unordered_map<int, int> mp;

		for (int num : nums) {
			st.insert(num);
		}

		int distinct = st.size();

		while (j < nums.size()) {
			mp[nums[j]]++;

			while (mp.size() == distinct) {
				ans += (nums.size() - j);

				if (mp[nums[i]] == 1) {
					mp.erase(nums[i]);
				} else {
					mp[nums[i]]--;
				}
				i++;
			}
			j++;
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)