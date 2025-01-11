class Solution {
   public:
	bool canConstruct(string s, int k) {
		vector<int> count(26, 0);
		int n = s.size();

		if (k > n) {
			return false;
		}

		for (char ch : s) {
			count[ch - 'a']++;
		}

		int maxOdds = n % 2 == 0   ? k % 2 == 0 ? k : k - 1
		              : k % 2 == 0 ? k - 1
		                           : k;

		for (int i = 0; i < 26; i++) {
			if (count[i] % 2 != 0) {
				maxOdds--;
			}
		}

		return maxOdds >= 0;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)