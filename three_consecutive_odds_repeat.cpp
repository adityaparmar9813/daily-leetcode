class Solution {
   public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		int oddCount = 0;

		for (int num : arr) {
			if (num % 2 != 0) {
				oddCount++;
			} else {
				oddCount = 0;
			}

			if (oddCount == 3) {
				return true;
			}
		}

		return false;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)