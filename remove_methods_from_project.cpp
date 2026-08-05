constexpr int MAXN = 100005;

class Solution {
   public:
	vector<int> remainingMethods(int n, int k,
	                             vector<vector<int>>& invocations) {
		vector<vector<int>> edges(n);
		vector<int> inDegree(n, 0);

		bitset<MAXN> sus;

		for (const auto& inv : invocations) {
			edges[inv[0]].push_back(inv[1]);
			inDegree[inv[1]]++;
		}

		queue<int> q;
		q.push(k);

		sus.set(k);

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : edges[u]) {
				inDegree[v]--;

				if (!sus.test(v)) {
					q.push(v);
					sus.set(v);
				}
			}
		}

		bool canRemoveAll = true;
		vector<int> rem;

		for (int i = 0; i < n; i++) {
			if (sus.test(i) && inDegree[i] > 0) {
				canRemoveAll = false;
				break;
			} else if (!sus.test(i)) {
				rem.push_back(i);
			}
		}

		if (!canRemoveAll) {
			vector<int> allNodes(n);
			iota(allNodes.begin(), allNodes.end(), 0);
			return allNodes;
		}

		return rem;
	}
};

// Time Complexity : O(N + E)
// Space Complexity : O(N + E)