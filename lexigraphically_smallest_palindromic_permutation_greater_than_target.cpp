class Solution {
   public:
	string lexPalindromicPermutation(string s, string target) {
		int n = s.size();
		vector<int> freq(26, 0);
		for (char ch : s) {
			freq[ch - 'a']++;
		}

		int odd = 0;
		char mid = 0;
		vector<int> half_count(26, 0);

		for (int i = 0; i < 26; i++) {
			if (freq[i] % 2 != 0) {
				odd++;
				mid = i + 'a';
			}
			half_count[i] = freq[i] / 2;
		}

		if (odd > 1) {
			return "";
		}

		auto build_palindrome = [&](string half) {
			string res = half;
			if (odd == 1) res += mid;
			string rev = half;
			reverse(rev.begin(), rev.end());
			res += rev;
			return res;
		};

		string temp = "";
		int i = 0;

		while (i < n / 2) {
			if (half_count[target[i] - 'a'] > 0) {
				half_count[target[i] - 'a']--;
				temp += target[i];
				i++;
			} else {
				break;
			}
		}

		if (i == n / 2) {
			string ans = build_palindrome(temp);
			if (ans > target) {
				return ans;
			}

			i--;
			if (i >= 0) {
				half_count[target[i] - 'a']++;
				temp = temp.substr(0, i);
			}
		}

		bool valid = false;

		while (i >= 0) {
			int idx = target[i] - 'a' + 1;
			while (idx < 26) {
				if (half_count[idx] > 0) {
					temp += char(idx + 'a');
					half_count[idx]--;
					valid = true;
					break;
				}
				idx++;
			}

			if (valid) {
				for (int j = 0; j < 26; j++) {
					while (half_count[j] > 0) {
						temp += char(j + 'a');
						half_count[j]--;
					}
				}
				break;
			}

			i--;
			if (i >= 0) {
				half_count[target[i] - 'a']++;
				temp = temp.substr(0, i);
			}
		}

		if (!valid) {
			return "";
		}

		return build_palindrome(temp);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)