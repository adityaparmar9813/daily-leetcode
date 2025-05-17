class Solution {
   public:
	inline void insert(vector<int>& nums, int num, int count, int& index) {
		while (count--) {
			nums[index++] = num;
		}
	}

	void sortColors(vector<int>& nums) {
		vector<int> count(3, 0);

		for (int num : nums) {
			count[num]++;
		}

		int index = 0;

		for (int i = 0; i <= 2; i++) {
			insert(nums, i, count[i], index);
		}
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)