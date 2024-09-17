class Solution {
  public:
	void breakWords(string s, unordered_map<string, int> &mp) {
		string curr = "";

		for (char ch : s) {
			if (ch == ' ') {
				mp[curr]++;
				curr = "";
			} else {
				curr.push_back(ch);
			}
		}

		mp[curr]++;
	}

	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> mp;
		breakWords(s1, mp);
		breakWords(s2, mp);
		vector<string> ans;

		for (const auto &[s, count] : mp) {
			cout << s << " ";
			if (count == 1) {
				ans.push_back(s);
			}
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)