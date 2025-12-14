class Solution {
   public:
	int numberOfWays(string corridor) {
		const int MOD = 1e9 + 7;
		int totalSeats = 0;

		for (char c : corridor) {
			if (c == 'S') totalSeats++;
		}

		if (totalSeats == 0 || totalSeats % 2 != 0) {
			return 0;
		}

		long long ways = 1;
		int seatCount = 0, plantCount = 0;
		bool inBetween = false;

		for (char c : corridor) {
			if (c == 'S') {
				seatCount++;
				if (seatCount % 2 == 0) {
					inBetween = true;
					plantCount = 0;
				} else if (inBetween) {
					ways = (ways * (plantCount + 1)) % MOD;
					inBetween = false;
				}
			} else if (inBetween) {
				plantCount++;
			}
		}

		return ways;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)