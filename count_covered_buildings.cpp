class Solution {
   public:
	int countCoveredBuildings(int n, vector<vector<int>>& v) {
		sort(v.begin(), v.end());

		unordered_map<int, vector<int>> x;
		unordered_map<int, vector<int>> y;

		for (auto it : v) {
			int i = it[0];
			int j = it[1];
			x[i].push_back(j);
			y[j].push_back(i);
		}

		int ans = 0;

		for (auto it : v) {
			int a = it[0];
			int b = it[1];

			vector<int>& temp = x[a];
			vector<int>& tp = y[b];

			int idx = lower_bound(temp.begin(), temp.end(), b) - temp.begin();
			int id = lower_bound(tp.begin(), tp.end(), a) - tp.begin();

			if (idx > 0 && idx < temp.size() - 1 && id > 0 &&
			    id < tp.size() - 1) {
				ans++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)