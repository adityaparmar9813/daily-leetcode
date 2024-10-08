class Solution {
  public:
	int minSwaps(string s) {
		int size = 0, count = 0;

		for (auto ch : s) {
			if (ch == '[') {
				size++;
			} else {
				if (size == 0) {
					count++;
				} else {
					size--;
				}
			}
		}

		int ans = count / 2;
		ans = count % 2 == 0 ? ans : ans + 1;
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)