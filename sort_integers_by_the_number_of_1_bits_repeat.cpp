class Solution {
   public:
	static bool sortHelper(int num1, int num2) {
		int ones1 = __builtin_popcount(num1), ones2 = __builtin_popcount(num2);

		if (ones1 == ones2) {
			return num1 < num2;
		}
		return ones1 < ones2;
	}
	vector<int> sortByBits(vector<int>& arr) {
		sort(arr.begin(), arr.end(), sortHelper);
		return arr;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)