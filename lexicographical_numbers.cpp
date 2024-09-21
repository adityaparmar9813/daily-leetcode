class Solution {
  public:
	vector<int> ans;

	void solve(int num, int n) {
		if (num > n) {
			return;
		}
		ans.push_back(num);

		solve(num * 10, n);

		if ((num + 1) % 10 != 0) {
			solve(num + 1, n);
		}
	}

	vector<int> lexicalOrder(int n) {
		solve(1, n);
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)