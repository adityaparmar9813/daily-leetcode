class Solution {
   public:
	vector<int> maxDepthAfterSplit(auto s) {
		int n = s.size();
		vector<int> res(n);

		for (int i = 0; i < n; i++) {
			res[i] = (i ^ s[i]) & 1;
		}

		return res;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)