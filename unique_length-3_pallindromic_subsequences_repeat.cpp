class Solution {
   public:
	int countPalindromicSubsequence(string s) {
		vector<int> first(26, -1), last(26, -1);
		int ans = 0;

		for (int i = 0; i < s.size(); i++) {
			int pos = s[i] - 'a';

			if (first[pos] == -1) {
				first[pos] = i;
			}
			last[pos] = i;
		}

		for (int i = 0; i < 26; i++) {
			vector<bool> visited(26, false);

			for (int j = first[i] + 1; j < last[i]; j++) {
				int pos = s[j] - 'a';
				if (visited[pos]) {
					continue;
				}

				ans++;
				visited[pos] = true;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)