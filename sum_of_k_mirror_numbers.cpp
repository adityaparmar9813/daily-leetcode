class Solution {
   public:
	bool isPalindrome(const string& s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l++] != s[r--]) return false;
		}
		return true;
	}

	string toBaseK(long long num, int k) {
		string res;
		while (num > 0) {
			res.push_back(char('0' + (num % k)));
			num /= k;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	void generatePalindromes(int length, vector<long long>& result) {
		if (length == 1) {
			for (int i = 1; i <= 9; i++) {
				result.push_back(i);
			}
			return;
		}

		int half = (length + 1) / 2;
		long long start = 1;

		for (int i = 1; i < half; i++) {
			start *= 10;
		}
		long long end = start * 10;

		for (long long i = start; i < end; i++) {
			string s = to_string(i);
			string rev = s.substr(0, length % 2 ? s.size() - 1 : s.size());
			reverse(rev.begin(), rev.end());
			result.push_back(stoll(s + rev));
		}
	}

	long long kMirror(int k, int n) {
		long long total = 0;
		int count = 0;
		int length = 1;

		while (count < n) {
			vector<long long> pals;
			generatePalindromes(length, pals);

			for (long long x : pals) {
				if (isPalindrome(toBaseK(x, k))) {
					total += x;

					if (++count == n) {
						return total;
					}
				}
			}
			length++;
		}

		return total;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)