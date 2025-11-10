class Solution {
   public:
	int minOperations(vector<int>& nums) {
		vector<int> st;
		int ans = 0;

		for (int num : nums) {
			while (!st.empty() && st.back() > num) {
				st.pop_back();
				ans++;
			}
			if (num > 0 && (st.empty() || st.back() != num)) {
				st.push_back(num);
			}
		}

		return ans + (int)st.size();
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)