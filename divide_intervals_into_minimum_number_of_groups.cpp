class Solution {
  public:
	int minGroups(vector<vector<int>> &intervals) {
		vector<int> mp(1e6 + 2, 0);

		for (vector<int> interval : intervals) {
			mp[interval[0]] += 1;
			mp[interval[1] + 1] -= 1;
		}

		int curr = 0, ans = 0;
		;

		for (int i = 1; i < mp.size() - 1; i++) {
			curr += mp[i];
			mp[i] = curr;
			ans = max(ans, curr);
		}
		return ans;
	}
};

// Time Complexity : O(r - l)
// Space Complexity : O(r - l)