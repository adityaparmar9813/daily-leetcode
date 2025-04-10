class Solution {
   public:
	vector<vector<long long>> memoization;

	long long countPowerfulIntegers(long long x, int limit, string suffix) {
		string xStr = to_string(x);
		int xSize = xStr.size();
		memoization.assign(17, vector<long long>(2, -1));
		int indexDifference = xSize - (int)suffix.size();

		if (indexDifference < 0) {
			return 0;
		}

		function<long long(int, int)> countRecursive =
		    [&](int index, int tight) -> long long {
			if (index == xSize) {
				return 1;
			}

			long long &answer = memoization[index][tight];
			if (answer != -1) {
				return answer;
			}

			answer = 0;

			if (index >= indexDifference) {
				int current_digit = suffix[index - indexDifference] - '0';
				if (current_digit <= limit) {
					if (tight && current_digit <= xStr[index] - '0') {
						answer += countRecursive(
						    index + 1, current_digit == xStr[index] - '0');
					} else if (!tight) {
						answer += countRecursive(index + 1, 0);
					}
				}
			} else if (tight) {
				int digit = xStr[index] - '0';
				for (int current_digit = 0; current_digit <= min(limit, digit);
				     ++current_digit) {
					answer += countRecursive(index + 1, current_digit == digit);
				}
			} else {
				for (int current_digit = 0; current_digit <= limit;
				     ++current_digit) {
					answer += countRecursive(index + 1, 0);
				}
			}

			return answer;
		};

		return countRecursive(0, 1);
	}

	long long numberOfPowerfulInt(long long start, long long finish, int limit,
	                              string suffix) {
		return countPowerfulIntegers(finish, limit, suffix) -
		       countPowerfulIntegers(start - 1, limit, suffix);
	}
};

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)