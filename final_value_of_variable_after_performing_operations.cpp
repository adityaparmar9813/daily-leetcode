class Solution {
   public:
	int finalValueAfterOperations(vector<string>& operations) {
		int res = 0;

		for (const auto& operation : operations) {
			if (operation[0] == '-' || operation[2] == '-') {
				res--;
			} else {
				res++;
			}
		}

		return res;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)