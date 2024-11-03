class Solution {
  public:
	bool rotateString(string s, string goal) {
		if (s.length() != goal.length()) {
			return false;
		}

		string repeat = s.append(s);
		return repeat.find(goal) != -1;
	}
};

// Time Complexity : O(n)
// Space Complexity: O(n)