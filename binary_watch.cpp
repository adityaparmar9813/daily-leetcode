class Solution {
   public:
	int popCount(int num) {
		int res = 0;

		while (num != 0) {
			res += (num % 2 == 1);
			num /= 2;
		}

		return res;
	}

	vector<string> readBinaryWatch(int turnedOn) {
		vector<string> ans;

		for (int h = 0; h < 12; h++) {
			for (int m = 0; m < 60; m++) {
				if (popCount(h) + popCount(m) == turnedOn) {
					ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
					              to_string(m));
				}
			}
		}

		return ans;
	}
};

// Time Complexity: O(1)
// Space Complexity: O(1)