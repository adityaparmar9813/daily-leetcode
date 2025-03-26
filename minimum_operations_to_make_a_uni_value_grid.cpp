class Solution {
   public:
	int minOperations(vector<vector<int>>& grid, int x) {
		vector<int> elements;
		for (auto& row : grid) {
			for (int num : row) {
				elements.push_back(num);
			}
		}

		sort(elements.begin(), elements.end());
		int median = elements[elements.size() / 2];
		int ops = 0;

		for (auto& row : grid) {
			for (int num : row) {
				if ((num - median) % x != 0) {
					return -1;
				}
				ops += abs(num - median) / x;
			}
		}

		return ops;
	}
};

// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)