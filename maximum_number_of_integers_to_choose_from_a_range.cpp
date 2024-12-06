class Solution {
  public:
	int maxCount(vector<int> &banned, int n, int maxSum) {
		int cnt = 0;
		sort(banned.begin(), banned.end());

		for (int i = 1, j = 0; i <= n; i++) {
			if (maxSum - i < 0) {
				break;
			}
			while (j < banned.size() && banned[j] < i) {
				j++;
			}

			if (j < banned.size() && banned[j] == i) {
				j++;
				continue;
			}

			cnt++;
			maxSum -= i;
		}

		return cnt;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)