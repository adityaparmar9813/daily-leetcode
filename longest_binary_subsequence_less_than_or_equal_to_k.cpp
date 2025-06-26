class Solution {
   public:
	int longestSubsequence(string s, int k) {
		int n = s.size();
		int cnt = 0;
		long long val = 0;
		int power = 0;

		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == '0') {
				cnt++;
			} else {
				if (power < 32 && (val + (1LL << power)) <= k) {
					val += (1LL << power);
					cnt++;
				}
			}
			power++;
		}
		return cnt;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)