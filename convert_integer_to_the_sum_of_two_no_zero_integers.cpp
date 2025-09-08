class Solution {
   public:
	bool hasZero(int n) {
		while (n != 0) {
			if (n % 10 == 0) {
				return true;
			}
			n /= 10;
		}

		return false;
	}

	vector<int> getNoZeroIntegers(int n) {
		int i = 1;

		while (i < n) {
			if (!hasZero(i) && !hasZero(n - i)) {
				break;
			}
			i++;
		}

		return {i, n - i};
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(1)