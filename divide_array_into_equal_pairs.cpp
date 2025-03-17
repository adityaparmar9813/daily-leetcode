class Solution {
   public:
	bool divideArray(vector<int>& nums) {
		vector<int> mp(501, 0);

		for (int num : nums) {
			mp[num]++;
		}

		for (int count : mp) {
			if (count % 2 != 0) {
				return false;
			}
		}

		return true;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)