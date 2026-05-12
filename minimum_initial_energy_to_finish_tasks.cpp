class Solution {
   public:
	int minimumEffort(vector<vector<int>>& shop) {
		sort(shop.begin(), shop.end(), [&](vector<int>& a, vector<int>& b) {
			return a[1] - a[0] > b[1] - b[0];
		});

		int start = shop[0][1];
		int bal = shop[0][1] - shop[0][0];
		int loan = 0;

		for (int i = 1; i < shop.size(); i++) {
			int cost = shop[i][0];
			int thresh = shop[i][1];

			if (bal < thresh) {
				loan += thresh - bal;
				bal = thresh;
			}

			bal -= cost;
		}

		return start + loan;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)