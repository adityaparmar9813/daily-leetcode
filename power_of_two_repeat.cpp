class Solution {
   public:
	bool isPowerOfTwo(int n) {
		return n == 0 ? false : floor(log2(n)) == ceil(log2(n));
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)