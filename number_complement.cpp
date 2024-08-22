class Solution {
  public:
	int findComplement(int num) {
		int shift = (log10(num) / log10(2)) + 1;
		int mask = -1 << shift;
		mask ^= -1;
		return mask ^ num;
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)