class Solution {
   public:
	long long getDescentPeriods(vector<int>& prices) {
		long long ans = 0;

		for (int i = 0; i < prices.size(); i++) {
			int curr = 1;

			while (i < prices.size() - 1 && prices[i] - prices[i + 1] == 1) {
				curr++;
				i++;
			}

			ans += (long long)curr * (curr + 1) / 2;
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)