class Solution {
   public:
	int n;
	vector<vector<int>> dp;

	int child1(vector<vector<int>>& fruits) {
		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans += fruits[i][i];
		}

		return ans;
	}

	int child2(vector<vector<int>>& fruits, int i, int j) {
		if (i >= n || j < 0 || j >= n) {
			return 0;
		}
		if (i == j || i > j) {
			return 0;
		}
		if (i == n - 1 && j == n - 1) {
			return 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int bottomLeft = fruits[i][j] + child2(fruits, i + 1, j - 1);
		int bottomRight = fruits[i][j] + child2(fruits, i + 1, j + 1);
		int bottom = fruits[i][j] + child2(fruits, i + 1, j);

		return dp[i][j] = max({bottomLeft, bottomRight, bottom});
	}

	int child3(vector<vector<int>>& fruits, int i, int j) {
		if (i >= n || j < 0 || j >= n) {
			return 0;
		}
		if (i == j || i < j) {
			return 0;
		}
		if (i == n - 1 && j == n - 1) {
			return 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int right = fruits[i][j] + child3(fruits, i, j + 1);
		int rightUp = fruits[i][j] + child3(fruits, i - 1, j + 1);
		int rightDown = fruits[i][j] + child3(fruits, i + 1, j + 1);

		return dp[i][j] = max({right, rightUp, rightDown});
	}

	int maxCollectedFruits(vector<vector<int>>& fruits) {
		n = fruits.size();

		dp.resize(n + 1, vector<int>(n + 1, -1));

		int c1 = child1(fruits);
		int c2 = child2(fruits, 0, n - 1);
		int c3 = child3(fruits, n - 1, 0);

		return c1 + c2 + c3;
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n ^ 2)