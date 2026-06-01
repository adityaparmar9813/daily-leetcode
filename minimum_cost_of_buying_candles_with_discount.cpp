class Solution {
   public:
	int minimumCost(vector<int>& cost) {
		int ans = 0, turn = 0;
		sort(cost.begin(), cost.end());

		for (int i = cost.size() - 1; i >= 0; i--) {
			if (turn == 2) {
				turn = 0;
				continue;
			}
			ans += cost[i];
			turn++;
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)