class Solution {
   public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		set<string> st;
		vector<string> ans;

		for (string f : folder) {
			string curr = "";
			bool flag = true;

			for (char ch : f) {
				curr.push_back(ch);
				if (st.find(curr) != st.end()) {
					flag = false;
					break;
				}
			}

			if (flag) {
				ans.push_back(f);
			}
			st.insert(f + '/');
		}

		return ans;
	}
};

// Time Complexity: O(n * m * log(n))
// Space Complexity: O(n * m)