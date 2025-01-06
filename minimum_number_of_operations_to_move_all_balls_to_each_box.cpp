class Solution {
   public:
	vector<int> minOperations(string boxes) {
		int n = boxes.size();
		vector<int> ans(n, 0);

		int ballsFound = 0, cost = 0;

		for (int i = 0; i < n; i++) {
			cost += ballsFound;
			ans[i] = cost;
			ballsFound += boxes[i] == '1';
		}

		ballsFound = 0, cost = 0;

		for (int i = n - 1; i >= 0; i--) {
			cost += ballsFound;
			ans[i] += cost;
			ballsFound += boxes[i] == '1';
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)