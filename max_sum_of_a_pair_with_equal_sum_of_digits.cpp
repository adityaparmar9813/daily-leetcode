class Solution {
   public:
	inline int digitSum(int num) {
		int sum = 0;

		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}

		return sum;
	}

	int maximumSum(vector<int>& nums) {
		vector<int> mp(82, -1);
		int ans = -1;

		for (int num : nums) {
			int digSum = digitSum(num);

			if (mp[digSum] == -1) {
				mp[digSum] = num;
				continue;
			}

			ans = max(ans, mp[digSum] + num);
			mp[digSum] = max(mp[digSum], num);
		}

		return ans;
	}
};

// Time Complexity: O(n * log(max(nums)))
// Space Complexity: O(1)