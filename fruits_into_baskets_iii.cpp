class Solution {
	int n;
	vector<int> segmentTree;
	void build(int v, int l, int r, vector<int>& baskets) {
		if (l == r) {
			segmentTree[v] = baskets[l];
		} else {
			int mid = (l + r) / 2;
			build(2 * v, l, mid, baskets);
			build(2 * v + 1, mid + 1, r, baskets);
			segmentTree[v] = max(segmentTree[2 * v], segmentTree[2 * v + 1]);
		}
	}
	void update(int v, int l, int r, int pos, int val) {
		if (l == r) {
			segmentTree[v] = val;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid)
			update(2 * v, l, mid, pos, val);
		else
			update(2 * v + 1, mid + 1, r, pos, val);
		segmentTree[v] = max(segmentTree[2 * v], segmentTree[2 * v + 1]);
	}
	int firstLarger(int v, int p, int l, int r) {
		if (segmentTree[p] < v) return r + 1;
		if (l == r) return r;
		int mid = (l + r) / 2;
		int lf = firstLarger(v, 2 * p, l, mid);
		if (lf <= mid) return lf;
		return firstLarger(v, 2 * p + 1, mid + 1, r);
	}

   public:
	int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
		int res = 0;
		int n = baskets.size();
		segmentTree.assign(4 * n, 0);
		build(1, 0, n - 1, baskets);
		for (int fruit : fruits) {
			int s = firstLarger(fruit, 1, 0, n - 1);
			if (s == n)
				res++;
			else
				update(1, 0, n - 1, s, 0);
		}
		return res;
	}
};

// Time Complexity: O(m * log(n))
// Space Complexity: O(n)