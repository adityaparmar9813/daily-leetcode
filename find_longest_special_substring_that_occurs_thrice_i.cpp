class Solution {
  public:
	int maximumLength(string s) {
		int n = s.size();
		unordered_map<string, int> mp;
		int ans = -1;

		for (int len = 1; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				string sub = s.substr(i, len);

				if (isSpecial(sub)) {
					mp[sub]++;

					if (mp[sub] >= 3) {
						ans = max(ans, len);
					}
				}
			}
		}

		return ans;
	}

  private:
	bool isSpecial(const string &s) {
		char c = s[0];

		for (char ch : s) {
			if (ch != c)
				return false;
		}

		return true;
	}
};
