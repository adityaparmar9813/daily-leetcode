class Solution {
   public:
	bool solve(vector<int>& bits, int index) {
		if (index == bits.size()) {
			return false;
		}
		if (index == bits.size() - 1) {
			return true;
		}
		return bits[index] == 0 ? solve(bits, index + 1)
		                        : solve(bits, index + 2);
	}

	bool isOneBitCharacter(vector<int>& bits) { return solve(bits, 0); }
};

// Time Complexity : O(n)
// Space Complexity : O(1)