class Solution {
   public:
	int n, m;
	vector<string> strs;
	unordered_map<string, int> memo[105];

	int dfs(int col, bitset<105>& mask) {
		if (col == m) return 0;

		string key = mask.to_string();
		if (memo[col].count(key)) return memo[col][key];

		int ans = 1 + dfs(col + 1, mask);

		bitset<105> next = mask;
		bool ok = true;

		for (int i = 0; i + 1 < n; i++) {
			if (mask[i]) {
				continue;
			}

			if (strs[i][col] > strs[i + 1][col]) {
				ok = false;
				break;
			}
			if (strs[i][col] < strs[i + 1][col]) {
				next.set(i);
			}
		}

		if (ok) {
			ans = min(ans, dfs(col + 1, next));
		}

		return memo[col][key] = ans;
	}

	int minDeletionSize(vector<string>& s) {
		strs = s;
		n = strs.size();
		m = strs[0].size();

		bitset<105> mask;
		return dfs(0, mask);
	}
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)