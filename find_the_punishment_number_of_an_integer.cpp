class Solution {
   public:
	bool check(string s, int target, int sum, int index) {
		if (index == s.size()) {
			return sum == target;
		}

		int curr = 0;

		for (int i = index; i < s.size(); i++) {
			curr = curr * 10 + (s[i] - '0');

			if (check(s, target, sum + curr, i + 1)) {
				return true;
			}
		}

		return false;
	}

	int punishmentNumber(int n) {
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			int square = i * i;

			if (check(to_string(square), i, 0, 0)) {
				ans += square;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(log(n))