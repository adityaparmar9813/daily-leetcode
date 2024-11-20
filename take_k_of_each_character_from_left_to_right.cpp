class Solution {
  public:
	int takeCharacters(string s, int k) {
		int n = s.size();
		vector<int> arr = {0, 0, 0};
		int ans = 0;

		if (!k) {
			return 0;
		}

		for (auto x : s) {
			arr[x - 'a']++;
		}

		if (arr[0] < k || arr[1] < k || arr[2] < k) {
			return -1;
		}

		if ((arr[0] + arr[1] + arr[2]) == k * 3) {
			return n;
		}

		int i = 0, j = 0;

		while (j < n) {
			arr[s[j] - 'a']--;

			while ((arr[0] < k || arr[1] < k || arr[2] < k) && i < j) {
				arr[s[i] - 'a']++;
				i++;
			}

			ans = max(ans, j - i + 1);
			j++;
		}

		return n - ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)