class Solution {
   public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> groupSize(n, 1), prevElement(n, -1);
		int maxIndex = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
					groupSize[i] = groupSize[j] + 1;
					prevElement[i] = j;
				}
			}
			if (groupSize[i] > groupSize[maxIndex]) {
				maxIndex = i;
			}
		}

		vector<int> result;
		for (int i = maxIndex; i != -1; i = prevElement[i]) {
			result.insert(result.begin(), nums[i]);
		}
		return result;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)