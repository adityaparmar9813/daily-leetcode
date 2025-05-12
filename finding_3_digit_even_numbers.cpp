class Solution {
   public:
	vector<int> findEvenNumbers(vector<int>& digits) {
		sort(digits.begin(), digits.end());
		set<int> st;
		int n = digits.size();

		for (int i = 0; i < n; i++) {
			if (digits[i] == 0) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				for (int k = 0; k < n; k++) {
					if (digits[k] % 2 != 0 || i == k || j == k) {
						continue;
					}
					st.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
				}
			}
		}

		return vector<int>(st.begin(), st.end());
	}
};

// Time Complexity: O(n ^ 3)
// Space Complexity: O(n)