class Solution {
   public:
	int minimumDeletions(string word, int k) {
		vector<int> mp(26, 0);

		for (char ch : word) {
			mp[ch - 'a']++;
		}

		sort(mp.begin(), mp.end());

		int ans = 1e9, prev = 0;

		for (int i = 0; i < 26; i++) {
			int curr = prev;

			for (int j = i + 1; j < 26; j++) {
				curr += max(0, mp[j] - mp[i] - k);
			}

			prev += mp[i];
			ans = min(ans, curr);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)