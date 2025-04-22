class Solution {
   public:
	int numberOfArrays(vector<int>& diff, int lower, int upper) {
		long sum = 0, maxi = 0, mini = 0;

		for (int d : diff) {
			sum += d;
			maxi = max(maxi, sum);
			mini = min(mini, sum);
		}

		return max(0L, upper - lower - maxi + mini + 1);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)