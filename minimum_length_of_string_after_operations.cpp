class Solution {
   public:
	int minimumLength(string s) {
		vector<int> mp(26, 0);
		int ans = 0;

		for (char ch : s) {
			mp[ch - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			ans += mp[i] < 3 ? mp[i] : mp[i] % 2 == 0 ? 2 : 1;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)