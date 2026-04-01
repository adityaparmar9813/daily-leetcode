class Solution {
   public:
	vector<int> survivedRobotsHealths(vector<int>& d, vector<int>& h,
	                                  string dir) {
		vector<int> ans;
		vector<pair<int, pair<int, int>>> v;

		for (int i = 0; i < d.size(); i++) {
			int val = (dir[i] == 'R') ? 1 : 0;
			v.push_back({d[i], {val, i}});
		}

		sort(v.begin(), v.end());

		stack<pair<int, pair<int, int>>> st;
		int i = 0;

		while (i < v.size()) {
			if (!st.empty() && v[i].second.first == 0 &&
			    st.top().second.first == 1) {
				if (h[v[i].second.second] > h[st.top().second.second]) {
					h[st.top().second.second] = 0;
					h[v[i].second.second]--;
					st.pop();
				} else if (h[v[i].second.second] < h[st.top().second.second]) {
					h[v[i].second.second] = 0;
					h[st.top().second.second]--;
					i++;
				} else {
					h[st.top().second.second] = 0;
					h[v[i].second.second] = 0;
					i++;
					st.pop();
				}
			} else {
				st.push(v[i]);
				i++;
			}
		}

		for (int i = 0; i < h.size(); i++) {
			if (h[i] != 0) {
				ans.push_back(h[i]);
			}
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)