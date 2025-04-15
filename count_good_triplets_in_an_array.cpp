struct SegmentTree {
	int n;
	vector<int> tree;

	SegmentTree(int size) : n(size), tree(4 * size, 0) {}

	void update(int idx, int l, int r, int pos, int val) {
		if (l == r) {
			tree[idx] += val;
			return;
		}

		int mid = (l + r) / 2;

		if (pos <= mid) {
			update(2 * idx, l, mid, pos, val);
		} else {
			update(2 * idx + 1, mid + 1, r, pos, val);
		}
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	}

	int query(int idx, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[idx];
		}

		int mid = (l + r) / 2;

		return query(2 * idx, l, mid, ql, qr) +
		       query(2 * idx + 1, mid + 1, r, ql, qr);
	}

	void add(int pos, int val) { update(1, 0, n - 1, pos, val); }

	int sum(int pos) { return query(1, 0, n - 1, 0, pos); }
};

class Solution {
   public:
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		const int n = nums1.size();
		vector<int> id2(n);

		for (int i = 0; i < n; i++) {
			id2[nums2[i]] = i;
		}

		vector<int> inv(n);

		for (int i = 0; i < n; i++) {
			inv[id2[nums1[i]]] = i;
		}

		SegmentTree tree(n);

		long long ans = 0;

		for (int x = 0; x < n; x++) {
			int pos = inv[x];
			long long L = tree.sum(pos);
			tree.add(pos, 1);
			long long R = (n - 1 - pos) - (x - L);
			ans += L * R;
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)