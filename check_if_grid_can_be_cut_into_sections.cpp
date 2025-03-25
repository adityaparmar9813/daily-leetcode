class Solution {
   public:
	bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
		return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
	}

   private:
	bool checkCuts(vector<vector<int>>& rectangles, int dim) {
		bool gap = false;

		sort(rectangles.begin(), rectangles.end(),
		     [dim](vector<int>& a, vector<int>& b) { return a[dim] < b[dim]; });

		int end = rectangles[0][dim + 2];

		for (int i = 1; i < rectangles.size(); i++) {
			if (end <= rectangles[i][dim]) {
				if (gap) {
					return true;
				} else {
					gap = true;
				}
			}

			end = max(end, rectangles[i][dim + 2]);
		}

		return false;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)