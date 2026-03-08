class Solution {
   public:
	string increment(string str) {
		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] == '0') {
				str[i] = '1';
				break;
			} else {
				str[i] = '0';
			}
		}

		return str;
	}

	string findDifferentBinaryString(vector<string>& nums) {
		sort(nums.begin(), nums.end());
		string curr(nums[0].size(), '0');

		for (string num : nums) {
			if (num != curr) {
				return curr;
			}
			curr = increment(curr);
		}

		return string(nums[0].size(), '1');
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)