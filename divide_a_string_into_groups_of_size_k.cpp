class Solution {
   public:
	vector<string> divideString(string s, int k, char fill) {
		int n = s.size(), index = 0, i = 0;
		vector<string> ans(ceil(n / (double)k));

		while (i < n) {
			for (int j = 0; j < k; j++) {
				if (i < n) {
					ans[index].push_back(s[i]);
					i++;
				} else {
					ans[index].push_back(fill);
				}
			}
			index++;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)