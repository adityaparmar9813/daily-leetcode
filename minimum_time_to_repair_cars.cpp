class Solution {
   public:
	bool check(vector<int>& ranks, int cars, long long mid) {
		for (int rank : ranks) {
			cars -= (int)sqrt((double)mid / rank);

			if (cars <= 0) {
				return true;
			}
		}

		return false;
	}

	long long repairCars(vector<int>& ranks, int cars) {
		long long l = 1,
		          r = *min_element(ranks.begin(), ranks.end()) * cars * 1ll *
		              cars,
		          ans;

		while (l <= r) {
			long long mid = l + (r - l) / 2;

			if (check(ranks, cars, mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * log(min(ranks)) * log(cars ^ 2))
// Space Complexity: O(1)