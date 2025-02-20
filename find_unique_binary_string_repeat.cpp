class Solution {
   public:
	string solve(string str, int n, set<string>& st) {
		if (str.size() == n) {
			if (st.find(str) == st.end()) {
				return str;
			}

			return "";
		}

		string zero = solve(str + '0', n, st);
		string one = solve(str + '1', n, st);

		return zero.size() > one.size() ? zero : one;
	}

	string findDifferentBinaryString(vector<string>& nums) {
		set<string> st;

		for (string num : nums) {
			st.insert(num);
		}

		return solve("", nums.size(), st);
	}
};

// Time Complexity: O(n * 2 ^ n)
// Space Complexity: O(n)