class Solution {
   public:
	bool doesValidArrayExist(vector<int>& derived) {
		int curr = 0;

		for (int i = 0; i < derived.size(); i++) {
			curr ^= derived[i];
		}

		return curr == 0;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)