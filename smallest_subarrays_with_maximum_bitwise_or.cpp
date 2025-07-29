class Solution {
   public:
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> store(n, vector<int>(32, -1));
		vector<int> nextOccurence(32, -1);

		for (int i = n - 1; i >= 0; i--) {
			int num = nums[i];
			for (int j = 0; j < 32; j++) {
				if ((num >> j) & 1) {
					nextOccurence[j] = i;
				}
				store[i][j] = nextOccurence[j];
			}
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int curr = i;

			for (int j = 0; j < 32; j++) {
				curr = max(curr, store[i][j]);
			}
			ans[i] = curr - i + 1;
		}

		return ans;
	}
};

// Time Complexity :O(n)
// Space Complexity : O(n)