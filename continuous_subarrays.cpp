class Solution {
  public:
	long long continuousSubarrays(vector<int> &nums) {
		multiset<int> window;
		long long totalCount = 0;
		int left = 0;

		for (int right = 0; right < nums.size(); ++right) {
			window.insert(nums[right]);

			while (*window.rbegin() - *window.begin() > 2) {
				window.erase(window.find(nums[left]));
				++left;
			}

			totalCount += (right - left + 1);
		}

		return totalCount;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)