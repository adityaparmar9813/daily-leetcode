class Solution {
  public:
	int minSubarray(vector<int> &nums, int p) {
		long long totalSum = accumulate(nums.begin(), nums.end(), 0ll);
		int remainder = totalSum % p;

		if (remainder == 0) {
			return 0;
		}

		long long prefixSum = 0;
		int minLength = nums.size();
		unordered_map<int, int> prefixMap;
		prefixMap[0] = -1;

		for (int i = 0; i < nums.size(); i++) {
			prefixSum = (prefixSum + nums[i]) % p;
			int targetRemainder = (prefixSum - remainder + p) % p;

			if (prefixMap.find(targetRemainder) != prefixMap.end()) {
				minLength = min(minLength, i - prefixMap[targetRemainder]);
			}

			prefixMap[prefixSum] = i;
		}

		return minLength < nums.size() ? minLength : -1;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)