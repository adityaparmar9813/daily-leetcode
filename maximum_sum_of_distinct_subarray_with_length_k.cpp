class Solution {
  public:
	long long maximumSubarraySum(vector<int> &nums, int k) {
		unordered_map<int, int> mp;
		long long sum = 0, ans = 0;
		int n = nums.size();

		for (int i = 0; i < k; i++) {
			if (mp[nums[i]] == 0) {
				sum += nums[i];
			}
			mp[nums[i]]++;
		}

		ans = mp.size() == k ? max(ans, sum) : ans;

		for (int i = k; i < n; i++) {
			int outElem = nums[i - k];
			mp[outElem]--;
			if (mp[outElem] == 0) {
				mp.erase(outElem);
				sum -= outElem;
			}

			int inElem = nums[i];
			if (mp[inElem] == 0) {
				sum += inElem;
			}
			mp[inElem]++;

			ans = mp.size() == k ? max(ans, sum) : ans;
		}

		return ans;
	}
};
