class Solution {
  public:
	vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
		int sum = accumulate(rolls.begin(), rolls.end(), 0);
		int m = rolls.size();

		int nSum = mean * (n + m) - sum;

		if (nSum > n * 6 || nSum < n) {
			return {};
		}

		vector<int> ans(n, 1);
		nSum -= n;

		for (int i = 0; i < n && nSum > 0; i++) {
			int add = min(nSum, 5);
			ans[i] += add;
			nSum -= add;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)