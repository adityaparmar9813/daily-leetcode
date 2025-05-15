class Solution {
   public:
	vector<string> getSubsequence(vector<string>& w, vector<int>& g,
	                              int start) {
		vector<string> res;

		for (int i = 0; i < w.size(); i++) {
			if (g[i] == start) {
				res.push_back(w[i]);
				start = 1 - start;
			}
		}

		return res;
	}

	vector<string> getLongestSubsequence(vector<string>& words,
	                                     vector<int>& groups) {
		vector<string> ans1 = getSubsequence(words, groups, 0);
		vector<string> ans2 = getSubsequence(words, groups, 1);

		return ans1.size() > ans2.size() ? ans1 : ans2;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)