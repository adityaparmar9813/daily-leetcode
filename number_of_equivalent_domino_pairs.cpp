class Solution {
   public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		vector<int> mp(100, 0);
		int ans = 0;

		for (vector<int> domino : dominoes) {
			ans += mp[domino[0] * 10 + domino[1]];
			mp[domino[0] * 10 + domino[1]]++;

			if (domino[0] != domino[1]) {
				mp[domino[1] * 10 + domino[0]]++;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)