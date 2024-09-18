class Solution {
  public:
	static bool sortHelper(int num1, int num2) {
		string s1 = to_string(num1);
		string s2 = to_string(num2);

		return s1 + s2 > s2 + s1;
	}
	string largestNumber(vector<int> &nums) {
		sort(nums.begin(), nums.end(), sortHelper);

		string ans = "";
		int i = 0;

		while (i < nums.size() && nums[i] == 0) {
			i++;
		}

		for (; i < nums.size(); i++) {
			ans += to_string(nums[i]);
		}
		return ans != "" ? ans : "0";
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)