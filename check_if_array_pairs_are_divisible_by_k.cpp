class Solution {
  public:
	bool canArrange(vector<int> &arr, int k) {
		vector<int> rem(k, 0);

		for (int num : arr) {
			int r = num % k;

			if (r < 0) {
				r += k;
			}
			rem[r]++;
		}

		if (rem[0] % 2 != 0) {
			return false;
		}

		for (int i = 1; i <= k / 2; i++) {
			if (rem[i] != rem[k - i]) {
				return false;
			}
		}
		return true;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(k)