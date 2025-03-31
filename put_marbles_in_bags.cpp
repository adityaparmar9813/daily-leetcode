class Solution {
   public:
	long long putMarbles(vector<int>& weights, int k) {
		vector<long long> store;
		long long mini = 0, maxi = 0;
		int n = weights.size();

		for (int i = 1; i < n; i++) {
			store.push_back(weights[i] + weights[i - 1]);
		}

		sort(store.begin(), store.end());

		for (int i = 0; i < k - 1; i++) {
			mini += store[i];
			maxi += store[n - i - 2];
		}

		return maxi - mini;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)