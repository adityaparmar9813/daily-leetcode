class Solution {
  public:
	long long minimumSteps(string &s) {
		int black = 0;
		long long swap = 0;

		for (char ch : s) {
			(ch == '1') ? black++ : swap += black;
		}
		return swap;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)