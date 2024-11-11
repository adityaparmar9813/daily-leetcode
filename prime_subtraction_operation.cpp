class Solution {
  public:
	bool primeSubOperation(vector<int> &nums) {
		int maxNum = *max_element(nums.begin(), nums.end());
		vector<bool> isPrime(maxNum + 1, true);
		vector<int> primes;

		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i <= maxNum; i++) {
			if (isPrime[i]) {
				primes.push_back(i);
				for (int j = i * 2; j <= maxNum; j += i) {
					isPrime[j] = false;
				}
			}
		}

		int prev = 0;
		for (int i = 0; i < nums.size(); i++) {
			int current = nums[i];
			auto it = upper_bound(primes.begin(), primes.end(), current - 1);
			bool found = false;

			while (it != primes.begin()) {
				--it;
				int prime = *it;
				if (current - prime > prev) {
					current -= prime;
					found = true;
					break;
				}
			}

			if (!found && current <= prev) {
				return false;
			}

			prev = current;
			nums[i] = current;
		}

		return true;
	}
};

// Time Complexity : O(n * log(n) + n * log(log(max(arr))))
// Space Complexity : O(max(arr))