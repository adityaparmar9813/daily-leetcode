class UnionFind {
	vector<int> parent, size;

   public:
	UnionFind(int n) {
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) return;

		if (size[rootX] < size[rootY]) {
			parent[rootX] = rootY;
			size[rootY] += size[rootX];
		} else {
			parent[rootY] = rootX;
			size[rootX] += size[rootY];
		}
	}
};

class Solution {
   public:
	vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
		int n = nums.size();
		UnionFind uf(n);

		vector<pair<int, int>> sorted;
		for (int i = 0; i < n; ++i) {
			sorted.push_back({nums[i], i});
		}
		sort(sorted.begin(), sorted.end());

		for (int i = 0; i < n - 1; ++i) {
			if (sorted[i + 1].first - sorted[i].first <= limit) {
				uf.unite(sorted[i].second, sorted[i + 1].second);
			}
		}

		unordered_map<int, set<int>> groups;
		for (int i = 0; i < n; ++i) {
			groups[uf.find(i)].insert(i);
		}

		for (auto& [_, indices] : groups) {
			vector<int> values;
			for (int idx : indices) {
				values.push_back(nums[idx]);
			}
			sort(values.begin(), values.end());

			int i = 0;
			for (int idx : indices) {
				nums[idx] = values[i++];
			}
		}

		return nums;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)