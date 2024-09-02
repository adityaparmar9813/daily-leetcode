class Solution {
  public:
	int chalkReplacer(vector<int> &chalk, int k) {
		long long total = accumulate(chalk.begin(), chalk.end(), 0ll);
		long long req = k % total;

		int index = 0;
		while (req - chalk[index] >= 0) {
			req -= chalk[index++];
		}
		return index;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)