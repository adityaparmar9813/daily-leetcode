class Solution {
   public:
	int smallestNumber(int n) {
		int curr = 2;

		while (curr < 1e9) {
			if (curr - 1 >= n) {
				return curr - 1;
			}
			curr *= 2;
		}

		return 1e9;
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)