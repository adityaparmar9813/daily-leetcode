class Solution {
   public:
	vector<int> separateDigits(vector<int>& nums) {
		vector<int> ans;

		for (int num : nums) {
			vector<int> curr;

			while (num != 0) {
				int r = num % 10;
				num /= 10;
				curr.push_back(r);
			}
			reverse(curr.begin(), curr.end());

			for (int c : curr) {
				ans.push_back(c);
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)