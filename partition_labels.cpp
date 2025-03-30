class Solution {
   public:
	vector<int> partitionLabels(string s) {
		vector<int> totalCount(26, 0);
		vector<int> ans;
		int curr = 1;

		for (char ch : s) {
			totalCount[ch - 'a']++;
		}

		vector<int> currCount(26, 0);

		for (char ch : s) {
			currCount[ch - 'a']++;
			bool split = true;

			for (int j = 0; j < 26; j++) {
				if (currCount[j] > 0 && totalCount[j] > currCount[j]) {
					split = false;
					break;
				}
			}

			if (split) {
				ans.push_back(curr);
				curr = 1;
			} else {
				curr++;
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)