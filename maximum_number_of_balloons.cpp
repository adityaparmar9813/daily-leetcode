class Solution {
   public:
	int maxNumberOfBalloons(string text) {
		vector<int> mp(26, 0);

		for (char ch : text) {
			mp[ch - 'a']++;
		}

		return min({mp[1], mp[0], mp[11] / 2, mp[14] / 2, mp[13]});
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)