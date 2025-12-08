class Solution {
   public:
	int countTriples(int n) {
		set<int> st;
		int ans = 0;

		for (int i = 1; i <= n; i++) {
			st.insert(pow(i, 2));
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (st.find(pow(i, 2) + pow(j, 2)) != st.end()) {
					ans++;
				}
			}
		}

		return ans;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)