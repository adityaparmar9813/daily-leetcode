class Solution {
   public:
	int longestBalanced(string s) {
		int n = s.size();
		vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

		for (int i = 0; i < n; i++) {
			prefix[i + 1] = prefix[i];
			prefix[i + 1][s[i] - 'a']++;
		}

		int l = 0, r = 0;

		for (int i = 0; i < n; i++) {
			for (int j = n; j > i; j--) {
				int freq = -1;
				bool balanced = true;

				for (int k = 0; k < 26; k++) {
					int cnt = prefix[j][k] - prefix[i][k];
					if (cnt == 0) continue;

					if (freq == -1) {
						freq = cnt;
					} else if (cnt != freq) {
						balanced = false;
						break;
					}
				}

				if (balanced) {
					if (j - i > r - l) {
						l = i;
						r = j;
					}
					break;
				}
			}
		}

		return r - l;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)