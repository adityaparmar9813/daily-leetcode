class Solution {
   public:
	int maxFrequency(vector<int>& nums, int k, int numOperations) {
		int maximum = 1, minimum = 1e5;

		for (int s : nums) {
			maximum = max(maximum, s);
			minimum = min(minimum, s);
		}

		int n = (maximum - minimum + 1) + 2 * k + 1;
		vector<int> operation(n, 0);
		vector<int> frequency(n, 0);

		for (int s : nums) {
			int start = s - minimum + k - k;
			int mid = s - minimum + k;
			int end = s - minimum + k + k + 1;

			if (k > 0) {
				operation[start]++;
				frequency[start]++;
				operation[mid]--;
				operation[mid + 1]++;
				operation[end]--;
				frequency[end]--;
			} else {
				frequency[mid]++;
				frequency[mid + 1]--;
			}
		}

		int result = 1, freq = 0, op = 0;

		for (int i = 0; i < n; i++) {
			op += operation[i];
			freq += frequency[i];
			int overCount = max(op - numOperations, 0);
			result = max(result, freq - overCount);
		}

		return result;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)