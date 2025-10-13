class Solution {
   public:
	vector<int> buildMp(string word) {
		vector<int> mp(26, 0);

		for (char ch : word) {
			mp[ch - 'a']++;
		}
		return mp;
	}

	vector<string> removeAnagrams(vector<string>& words) {
		vector<int> prevMp = buildMp(words[0]), mp;
		vector<string> ans = {words[0]};

		for (int i = 1; i < words.size(); i++) {
			mp = buildMp(words[i]);

			for (int j = 0; j < 26; j++) {
				if (prevMp[j] != mp[j]) {
					ans.push_back(words[i]);
					break;
				}
			}

			prevMp = mp;
		}

		return ans;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : (O(n))