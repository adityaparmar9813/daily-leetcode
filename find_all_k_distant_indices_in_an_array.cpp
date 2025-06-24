class Solution {
   public:
	vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
		int n = nums.size();
		vector<bool> isSpecial(n, false);

		int curr = 0;

		for (int i = 0; i < n; i++) {
			while (curr <= i) {
				if (nums[curr] == key && k >= i - curr) {
					isSpecial[i] = true;
					break;
				}

				curr++;
			}
		}

		curr = n - 1;

		for (int i = n - 1; i >= 0; i--) {
			while (curr >= i) {
				if (nums[curr] == key && k >= curr - i) {
					isSpecial[i] = true;
					break;
				}

				curr--;
			}
		}

		vector<int> ans;

		for (int i = 0; i < n; i++) {
			if (isSpecial[i]) {
				ans.push_back(i);
			}
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)