class Solution {
  public:
	int gcd(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	int getLcm(int a, int b) { return (a * b) / gcd(a, b); }

	string fractionAddition(string expression) {
		unordered_map<int, vector<pair<int, int>>> mp;
		vector<char> arr(expression.begin(), expression.end());

		int n = expression.length();
		int index = 0;
		int sign = 1;

		while (index < n) {
			char currChar = arr[index];

			if (currChar == '-') {
				sign = -1;
				index++;
			} else if (currChar == '+') {
				sign = 1;
				index++;
			}

			int num = 0, deno = 0;
			bool slash = false;

			while (index < n && arr[index] != '+' && arr[index] != '-') {
				if (arr[index] == '/') {
					slash = true;
					index++;
					continue;
				}

				if (!slash) {
					num = num * 10 + (arr[index] - '0');
				} else {
					deno = deno * 10 + (arr[index] - '0');
				}
				index++;
			}

			if (deno == 0)
				deno = 1;
			mp[deno].emplace_back(num, sign);
		}

		int lcm = 1;
		for (const auto &denoEntry : mp) {
			lcm = getLcm(lcm, denoEntry.first);
		}

		int totalNum = 0;
		for (const auto &entry : mp) {
			int deno = entry.first;

			for (const auto &numEntry : entry.second) {
				int num = numEntry.first, numSign = numEntry.second;
				totalNum += (numSign * num * (lcm / deno));
			}
		}
		int gcdValue = gcd(abs(totalNum), lcm);
		totalNum /= gcdValue;
		lcm /= gcdValue;

		if (lcm == 1) {
			return to_string(totalNum) + "/1";
		}
		return to_string(totalNum) + "/" + to_string(lcm);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)