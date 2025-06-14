class Solution {
   public:
	int transform(string num, char from, char to) {
		int res = 0;

		for (char ch : num) {
			if (ch == from) {
				res = res * 10 + (to - '0');
			} else {
				res = res * 10 + (ch - '0');
			}
		}

		return res;
	}

	int minMaxDifference(int num) {
		string str = to_string(num);
		int maxi = num;

		for (char ch : str) {
			if (ch != '9') {
				maxi = transform(str, ch, '9');
				break;
			}
		}

		return maxi - transform(str, str[0], '0');
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))