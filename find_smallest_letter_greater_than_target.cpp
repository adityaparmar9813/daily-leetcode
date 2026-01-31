class Solution {
   public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int n = letters.size();
		int l = 0, r = n - 1;
		char ans = letters[0];

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (letters[mid] > target) {
				r = mid - 1;
				ans = letters[mid];
			} else {
				l = mid + 1;
			}
		}

		return ans;
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)