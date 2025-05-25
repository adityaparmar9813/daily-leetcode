class Solution {
   public:
	int longestPalindrome(vector<string>& words) {
		unordered_map<string, int> mp;
		bool pallindromeFound = false;
		int ans = 0;

		for (string word : words) {
			mp[word]++;
		}

		for (string word : words) {
			if (mp[word] < 1) {
				continue;
			}

			mp[word]--;
			reverse(word.begin(), word.end());

			if (mp[word] > 0) {
				ans += 2;
			} else if (word[0] == word[1]) {
				pallindromeFound = true;
			}
			mp[word]--;
		}

		if (pallindromeFound) {
			ans++;
		}

		return ans * 2;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)