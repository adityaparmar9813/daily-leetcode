class Solution {
  public:
	int maxChunksToSorted(vector<int> &arr) {
		int n = arr.size();
		int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

		for (int i = 0; i < n; i++) {
			prefixSum += arr[i];

			sortedPrefixSum += i;

			if (prefixSum == sortedPrefixSum) {
				chunks++;
			}
		}
		return chunks;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)