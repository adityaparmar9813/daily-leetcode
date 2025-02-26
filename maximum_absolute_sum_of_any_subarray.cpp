class Solution {
   public:
	int maxAbsoluteSum(vector<int>& nums) {
		int curr = 0, smallest = 0, largest = 0;

		for (int i = 0; i < nums.size(); i++) {
			curr += nums[i];

			smallest = min(smallest, curr);
			largest = max(largest, curr);
		}

		return largest - smallest;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)