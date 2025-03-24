class Solution {
   public:
	int countDays(int days, vector<vector<int>>& meetings) {
		sort(meetings.begin(), meetings.end());
		int curr = 0, ans = 0;

		for (const auto& meeting : meetings) {
			ans += max(meeting[0] - curr - 1, 0);
			curr = max(curr, meeting[1]);
		}

		return ans + max(days - curr, 0);
	}
};

// Time CComplexity: O(n * log(n))
// Space Complexity: O(1)