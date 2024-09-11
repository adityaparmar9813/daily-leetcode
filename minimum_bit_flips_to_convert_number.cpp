class Solution {
  public:
	int minBitFlips(int start, int goal) {
		return bitset<32>(start ^ goal).count();
	}
};

// Time Complexity : O(1)
// Space Complexity : O(1)