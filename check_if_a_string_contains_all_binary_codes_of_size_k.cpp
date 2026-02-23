class Solution {
   public:
	bool hasAllCodes(string s, int k) {
		int n = s.size();
		if (k > n) return false;

		int total = 1 << k;
		vector<bool> seen(total, false);

		int mask = 0;
		int allOnes = total - 1;

		for (int i = 0; i < k; i++) {
			mask = (mask << 1) | (s[i] - '0');
		}
		seen[mask] = true;
		int count = 1;

		for (int i = k; i < n; i++) {
			mask = ((mask << 1) & allOnes) | (s[i] - '0');
			if (!seen[mask]) {
				seen[mask] = true;
				count++;
				if (count == total) return true;
			}
		}

		return count == total;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)