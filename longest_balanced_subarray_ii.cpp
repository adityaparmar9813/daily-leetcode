class SegmentTree {
   public:
	int n;
	vector<int> sum, mn, mx;

	SegmentTree(int n_) : n(n_), sum(4 * n_, 0), mn(4 * n_, 0), mx(4 * n_, 0) {}

	void pull(int node) {
		int lc = node * 2, rc = node * 2 + 1;

		sum[node] = sum[lc] + sum[rc];
		mn[node] = min(mn[lc], sum[lc] + mn[rc]);
		mx[node] = max(mx[lc], sum[lc] + mx[rc]);
	}

	void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

	void update(int node, int l, int r, int idx, int val) {
		if (l == r) {
			sum[node] = val;
			mn[node] = val;
			mx[node] = val;
			return;
		}

		int m = (l + r) / 2;
		if (idx <= m)
			update(node * 2, l, m, idx, val);
		else
			update(node * 2 + 1, m + 1, r, idx, val);

		pull(node);
	}

	bool exist(int node, int sum_before, int target) const {
		int need = target - sum_before;
		return mn[node] <= need && need <= mx[node];
	}

	int find_rightmost_prefix(int target = 0) {
		return find_rightmost_prefix(1, 0, n - 1, 0, target);
	}

	int find_rightmost_prefix(int node, int l, int r, int sum_before,
	                          int target) {
		if (!exist(node, sum_before, target)) return -1;
		if (l == r) return l;

		int m = (l + r) / 2;
		int lc = node * 2, rc = node * 2 + 1;

		int sum_before_right = sum_before + sum[lc];
		if (exist(rc, sum_before_right, target))
			return find_rightmost_prefix(rc, m + 1, r, sum_before_right,
			                             target);

		return find_rightmost_prefix(lc, l, m, sum_before, target);
	}
};

class Solution {
   public:
	int longestBalanced(vector<int>& nums) {
		int n = nums.size();

		SegmentTree stree(n);
		unordered_map<int, int> first;

		int result = 0;
		for (int l = n - 1; l >= 0; --l) {
			int x = nums[l];

			auto it = first.find(x);
			if (it != first.end()) stree.update(it->second, 0);

			first[x] = l;
			stree.update(l, ((x & 1) == 0) ? 1 : -1);

			int r = stree.find_rightmost_prefix(0);
			if (r >= l) result = max(result, r - l + 1);
		}

		return result;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)