class Solution {
   public:
	int minSumOfLengths(vector<int>& arr, int target) {
		int n = arr.size();
		vector<int> best(n, INT_MAX);
		int left = 0, sum = 0, answer = INT_MAX;

		for (int right = 0; right < n; ++right) {
			sum += arr[right];

			while (sum > target) {
				sum -= arr[left];
				++left;
			}

			if (sum == target) {
				int currentLength = right - left + 1;

				if (left > 0 && best[left - 1] != INT_MAX) {
					answer = min(answer, currentLength + best[left - 1]);
				}
				best[right] = currentLength;
			}

			if (right > 0) {
				best[right] = min(best[right], best[right - 1]);
			}
		}

		return answer == INT_MAX ? -1 : answer;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)