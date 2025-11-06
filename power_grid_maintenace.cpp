class Solution {
	vector<int> parent;
	int findParent(int x) {
		if (parent[x] == x) return x;
		return parent[x] = findParent(parent[x]);
	}

   public:
	vector<int> processQueries(int c, vector<vector<int>>& conn,
	                           vector<vector<int>>& queries) {
		parent.resize(c + 1);
		for (int i = 0; i < c + 1; i++) parent[i] = i;
		for (int i = 0; i < conn.size(); i++) {
			int p1 = findParent(conn[i][0]);
			int p2 = findParent(conn[i][1]);
			parent[p1] = p2;
		}
		unordered_map<int, set<int>> mp;
		for (int i = 0; i < parent.size(); i++) {
			findParent(i);
			mp[parent[i]].insert(i);
		}
		vector<int> ans;
		for (int i = 0; i < queries.size(); i++) {
			int x = queries[i][1];
			if (queries[i][0] == 1) {
				if (mp[parent[x]].count(x))
					ans.push_back(x);
				else if (mp[parent[x]].size() == 0)
					ans.push_back(-1);
				else {
					auto itr = mp[parent[x]].begin();
					ans.push_back(*itr);
				}
			} else {
				mp[parent[x]].erase(x);
			}
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)