class Solution {
   public:
	using ll = long long;
	vector<int> ans;

	void backtrack(ll num, int low, int high) {
		if (num > high) {
			return;
		}
		if (num >= low) {
			ans.push_back(num);
		}
		if (num % 10 == 9) {
			return;
		}

		backtrack(num * 10 + (num % 10 + 1), low, high);
	}

	vector<int> sequentialDigits(int low, int high) {
		for (int i = 1; i < 10; i++) {
			backtrack(i, low, high);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};

// Time Complexity: O(9 ^ 2)
// Space Complexity: O(9 ^ 2)