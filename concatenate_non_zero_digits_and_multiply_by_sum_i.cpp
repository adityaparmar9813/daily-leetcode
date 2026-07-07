class Solution {
   public:
	long long sumAndMultiply(int n) {
		string str = to_string(n);
		long long x = 0, sum = 0;

		for (char ch : str) {
			if (ch == '0') {
				continue;
			}
			x = x * 10 + (ch - '0');
			sum += (ch - '0');
		}

		return x * sum;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)