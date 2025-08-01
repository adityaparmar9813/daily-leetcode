class Solution {
   public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> pascal;
		pascal.push_back({1});

		for (int i = 1; i < numRows; i++) {
			vector<int> curr = {1};

			for (int j = 0; j < i - 1; j++) {
				curr.push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
			}

			curr.push_back(1);
			pascal.push_back(curr);
		}

		return pascal;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)