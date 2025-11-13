class Solution {
   public:
	int maxOperations(string s) {
		int oneCount = 0, ans = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				oneCount++;
			} else {
				while (s[i] == '0') {
					i++;
				}
				ans += oneCount;
				i--;
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)