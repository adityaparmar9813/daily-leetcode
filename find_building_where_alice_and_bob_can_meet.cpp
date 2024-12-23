class Solution {
  public:
	int n, sparseTable[50010][20], logValues[50010];

	int queryMaximum(int left, int right) {
		int k = logValues[right - left + 1];
		return max(sparseTable[left][k], sparseTable[right - (1 << k) + 1][k]);
	}

	vector<int> leftmostBuildingQueries(vector<int> &heights,
										vector<vector<int>> &queries) {
		int n = heights.size();
		sparseTable[n][0] = 2e9;
		logValues[0] = -1;
		for (int i = 1; i <= n; i++) {
			logValues[i] = logValues[i >> 1] + 1;
		}
		for (int i = 0; i < n; i++) {
			sparseTable[i][0] = heights[i];
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j + (1 << i) - 1 <= n; j++) {
				sparseTable[j][i] = max(sparseTable[j][i - 1],
										sparseTable[j + (1 << (i - 1))][i - 1]);
			}
		}
		int numQueries = queries.size();
		vector<int> results(numQueries);
		for (int queryIndex = 0; queryIndex < numQueries; queryIndex++) {
			int left = queries[queryIndex][0], right = queries[queryIndex][1];
			if (left > right)
				swap(left, right);
			if (left == right) {
				results[queryIndex] = left;
				continue;
			}
			if (heights[right] > heights[left]) {
				results[queryIndex] = right;
				continue;
			}
			int maxHeight = max(heights[right], heights[left]);
			int low = right, high = n, mid;
			while (low < high) {
				mid = (low + high) >> 1;
				if (queryMaximum(right, mid) > maxHeight) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			results[queryIndex] = (low == n) ? -1 : low;
		}
		return results;
	}
};

// Time Complexity: O(n * log(n) + q * log(n))
// Space Complexity: O(n * log(n))