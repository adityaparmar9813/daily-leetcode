class Solution {
   public:
	const int MOD = 1e9 + 7;

	long long modExp(long long base, long long exp) {
		if (exp == 0) return 1;

		long long half = modExp(base, exp / 2);
		long long result = (half * half) % MOD;

		if (exp % 2) result = (result * base) % MOD;

		return result;
	}

	int xorAfterQueries(vector<int>& arr, vector<vector<int>>& ops) {
		int len = arr.size();

		int block = sqrt(len) + 1;

		vector<vector<vector<int>>> buckets(block);

		for (auto& query : ops) {
			int left = query[0];
			int right = query[1];
			int step = query[2];
			int val = query[3];

			if (step < block) {
				buckets[step].push_back(query);
			} else {
				for (int pos = left; pos <= right; pos += step) {
					arr[pos] = (1LL * arr[pos] * val) % MOD;
				}
			}
		}

		for (int step = 1; step < block; step++) {
			if (buckets[step].empty()) continue;

			vector<long long> multiplier(len + step + 5, 1);

			for (auto& query : buckets[step]) {
				int left = query[0];
				int right = query[1];
				int val = query[3];

				int lastIndex = left + ((right - left) / step) * step;
				int stop = lastIndex + step;

				multiplier[left] = (multiplier[left] * val) % MOD;

				long long invVal = modExp(val, MOD - 2);
				multiplier[stop] = (multiplier[stop] * invVal) % MOD;
			}

			for (int i = 0; i < len; i++) {
				if (i - step >= 0) {
					multiplier[i] =
					    (multiplier[i] * multiplier[i - step]) % MOD;
				}
			}

			for (int i = 0; i < len; i++) {
				arr[i] = (1LL * arr[i] * multiplier[i]) % MOD;
			}
		}

		int ans = 0;
		for (int value : arr) {
			ans ^= value;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)