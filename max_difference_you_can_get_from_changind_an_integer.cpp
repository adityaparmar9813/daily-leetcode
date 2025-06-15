class Solution {
   public:
	int transform(string num, char from, char to) {
		string res = "";
		for (char ch : num) {
			if (ch == from) {
				res += to;
			} else {
				res += ch;
			}
		}
		if (res[0] == '0') return 0;
		return stoi(res);
	}

	int maxDiff(int num) {
		string str = to_string(num);

		int maxVal = num;
		for (char ch : str) {
			if (ch != '9') {
				maxVal = transform(str, ch, '9');
				break;
			}
		}

		int minVal;
		if (str[0] != '1') {
			minVal = transform(str, str[0], '1');
		} else {
			minVal = num;
			for (int i = 1; i < str.size(); ++i) {
				if (str[i] != '0' && str[i] != '1') {
					minVal = transform(str, str[i], '0');
					break;
				}
			}
		}

		return maxVal - minVal;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)