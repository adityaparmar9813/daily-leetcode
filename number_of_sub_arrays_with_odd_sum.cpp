class Solution {
   public:
	int numOfSubarrays(vector<int>& arr) {
		const int MOD = 1e9 + 7;
		int odd = 0, even = 1, result = 0, sum = 0;

		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if (sum % 2 == 1) {
				result = (result + even) % MOD;
				odd++;
			} else {
				result = (result + odd) % MOD;
				even++;
			}
		}

		return result;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)