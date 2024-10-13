class Solution {
  public:
	vector<int> smallestRange(vector<vector<int>> &nums) {
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			minHeap;
		int n = nums.size();
		vector<int> indices(n, 0);
		int currentMax = INT_MIN;
		int rangeStart = 0, rangeEnd = INT_MAX;

		for (int i = 0; i < n; i++) {
			minHeap.push({nums[i][0], i});
			currentMax = max(currentMax, nums[i][0]);
		}

		while (true) {
			auto [currentMin, listIdx] = minHeap.top();
			minHeap.pop();

			if (currentMax - currentMin < rangeEnd - rangeStart) {
				rangeStart = currentMin;
				rangeEnd = currentMax;
			}

			if (++indices[listIdx] == nums[listIdx].size()) {
				break;
			}

			int nextValue = nums[listIdx][indices[listIdx]];
			minHeap.push({nextValue, listIdx});
			currentMax = max(currentMax, nextValue);
		}

		return {rangeStart, rangeEnd};
	}
};

// Time Complexity : O(n * log(k))
// Space Complexity : O(k)