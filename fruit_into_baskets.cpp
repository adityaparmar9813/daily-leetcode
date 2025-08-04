class Solution {
   public:
	int totalFruit(vector<int>& fruits) {
		int n = fruits.size();
		int ans = 0;
		int basket[2] = {-1, -1}, cnt[2] = {0, 0};
		int lastRun = 0;

		for (int i = 0; i < n; i++) {
			int x = fruits[i];

			if (x == basket[1]) {
				cnt[1]++;
				lastRun++;
			} else if (x == basket[0]) {
				swap(basket[0], basket[1]);
				swap(cnt[0], cnt[1]);
				cnt[1]++;
				lastRun = 1;
			} else {
				basket[0] = exchange(basket[1], x);
				cnt[0] = exchange(lastRun, 1);
				cnt[1] = 1;
			}
			ans = max(ans, cnt[0] + cnt[1]);
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)