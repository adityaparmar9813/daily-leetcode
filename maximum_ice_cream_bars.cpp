class Solution {
   public:
	int maxIceCream(vector<int>& costs, int coins) {
		vector<int> count(1e5 + 1, 0);

		for (int cost : costs) {
			count[cost]++;
		}

		int ans = 0;

		for (int i = 1; i < count.size(); i++) {
			if (coins - i < 0) {
				break;
			}
			int q = min(count[i], coins / i);
			coins -= q * i;
			ans += q;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)