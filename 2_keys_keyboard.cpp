class Solution {
  public:
	int minSteps(int n) {
		int copy = 0, paste = 1, operation = 0;

		while (paste != n) {
			if (n % paste == 0) {
				copy = paste;
				operation += 1;
			}

			paste += copy;
			operation += 1;
		}
		return operation;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)