class Solution {
   public:
	int MOD = 1e9 + 7;

	int zigZagArrays(int n, int l, int r) {
		int m = r - l + 1;
		vector<long long> up(m + 1), down(m + 1);

		for (int v = 1; v <= m; v++) {
			up[v] = v - 1;
			down[v] = m - v;
		}

		vector<long long> pref(m + 1, 0);
		vector<long long> suff(m + 2, 0);
		vector<long long> newUp(m + 1), newDown(m + 1);

		for (int len = 3; len <= n; len++) {
			for (int i = 1; i <= m; i++) {
				pref[i] = (pref[i - 1] + down[i]) % MOD;
			}

			for (int i = m; i >= 1; i--) {
				suff[i] = (suff[i + 1] + up[i]) % MOD;
			}

			for (int x = 1; x <= m; x++) {
				newUp[x] = pref[x - 1];
				newDown[x] = suff[x + 1];
			}

			up = newUp;
			down = newDown;
		}

		long long ans = 0;
		for (int v = 1; v <= m; v++) {
			ans = (ans + up[v] + down[v]) % MOD;
		}

		return (int)ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)