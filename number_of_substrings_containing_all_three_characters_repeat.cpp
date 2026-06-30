class Solution {
   public:
	bool check(vector<int>& cnt) { return cnt[0] && cnt[1] && cnt[2]; }

	int numberOfSubstrings(string s) {
		vector<int> cnt(3, 0);
		int n = s.size(), l = 0, r = 0, ans = 0;

		while (l < n) {
			while (r < n && !check(cnt)) {
				cnt[s[r] - 'a']++;
				r++;
			}

			if (!check(cnt)) {
				break;
			}

			ans += (n - r + 1);
			cnt[s[l++] - 'a']--;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)