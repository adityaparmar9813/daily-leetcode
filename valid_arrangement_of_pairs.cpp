class Solution {
  public:
	vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
		vector<vector<int>> ans;
		unordered_map<int, int> mp;
		unordered_map<int, vector<int>> adj;

		for (auto it : pairs) {
			mp[it[0]]++;
			mp[it[1]]--;
			adj[it[0]].push_back(it[1]);
		}

		int starting = pairs[0][0];
		for (auto it : mp) {
			if (it.second == 1) {
				starting = it.first;
				break;
			}
		}

		vector<int> ref;
		stack<int> st;
		st.push(starting);

		while (st.size()) {
			auto &nodes = adj[st.top()];

			if (nodes.empty()) {
				ref.push_back(st.top());
				st.pop();
			} else {
				st.push(nodes.back());
				nodes.pop_back();
			}
		}

		for (int i = ref.size() - 1; i > 0; i--) {
			ans.push_back({ref[i], ref[i - 1]});
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)