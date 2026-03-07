class Solution {
   public:
	int minFlips(auto& s) {
		int n = s.length();
		int res = n;
		int op[2] = {0, 0};

		for (int i = 0; i < n; i++) {
			op[(s[i] ^ i) & 1]++;
		}

		for (int i = 0; i < n; i++) {
			op[(s[i] ^ i) & 1]--;
			op[(s[i] ^ (n + i)) & 1]++;
			res = min(res, min(op[0], op[1]));
		}

		return res;
	}
}

// Time Complexity: O(n)
// Space Complexity: O(1)