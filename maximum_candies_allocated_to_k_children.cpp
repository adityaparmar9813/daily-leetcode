class Solution {
   public:
	bool check(vector<int>& candies, int mid, long long k) {
		for (int i = 0; i < candies.size(); i++) {
			k -= candies[i] / mid;
		}
		return k <= 0;
	}
	int maximumCandies(vector<int>& candies, long long k) {
		int l = 1, r = *max_element(candies.begin(), candies.end()), ans = 0;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (check(candies, mid, k)) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)