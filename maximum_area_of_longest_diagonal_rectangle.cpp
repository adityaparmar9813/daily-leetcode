class Solution {
   public:
	int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
		int ans = 0, maxi = 0;

		for (int i = 0; i < dimensions.size(); i++) {
			int curr = pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2);

			if (curr > maxi) {
				maxi = curr;
				ans = dimensions[i][0] * dimensions[i][1];
			} else if (curr == maxi) {
				ans = max(ans, dimensions[i][0] * dimensions[i][1]);
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)