class Solution {
  public:
	int getLucky(string s, int k) {
		vector<int> convert;

		for (char ch : s) {
			int val = ch - 'a' + 1;

			if (val < 10) {
				convert.push_back(val);
			} else {
				convert.push_back(val / 10);
				convert.push_back(val % 10);
			}
		}

		int ans = accumulate(convert.begin(), convert.end(), 0);
		cout << ans;

		while (--k) {
			int curr = ans, newAns = 0;

			while (curr != 0) {
				int r = curr % 10;
				curr = curr / 10;

				newAns += r;
			}
			ans = newAns;
		}
		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)