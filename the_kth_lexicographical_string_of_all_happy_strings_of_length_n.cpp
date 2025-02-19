class Solution {
   public:
	int copy;
	string dfs(string prefix, int n, int k) {
		if (n == 0) {
			return prefix;
		}

		for (char ch = 'a'; ch <= 'c'; ch++) {
			if (!prefix.empty() && ch == prefix.back()) {
				continue;
			}

			int cnt = (1 << (copy - prefix.length() - 1));

			if (cnt >= k) {
				return dfs(prefix + ch, n - 1, k);
			} else {
				k -= cnt;
			}
		}

		return "";
	}
	string getHappyString(int n, int k) {
		copy = n;
		return dfs("", n, k);
	}
};

// Time Complexity: O(3 ^ n)
// Space Complexity: O(n)