class Solution {
   public:
	int maxSumDivThree(vector<int>& nums) {
		int total = 0;
		int min1_1 = 1e4, min1_2 = 1e4, min2_1 = 1e4, min2_2 = 1e4;

		for (int num : nums) {
			total += num;
			int rem = num % 3;

			if (rem == 1) {
				if (num < min1_1) {
					min1_2 = min1_1;
					min1_1 = num;
				} else if (num < min1_2) {
					min1_2 = num;
				}
			} else if (rem == 2) {
				if (num < min2_1) {
					min2_2 = min2_1;
					min2_1 = num;
				} else if (num < min2_2) {
					min2_2 = num;
				}
			}
		}

		if (total % 3 == 0) {
			return total;
		}

		if (total % 3 == 1) {
			int op1 = min1_1;
			int op2 = min2_1 + min2_2;
			return total - min(op1, op2);
		}

		return total - min(min2_1, min1_1 + min1_2);
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)