class Solution {
   public:
	int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
	                           vector<int>& vBars) {
		int maxConsecutiveHBars = 1;
		int maxConsecutiveVBars = 1;

		sort(hBars.begin(), hBars.end());
		sort(vBars.begin(), vBars.end());

		int hLength = hBars.size();
		int vLength = vBars.size();

		int tempH = 1;
		int tempV = 1;

		for (int i = 1; i < max(hLength, vLength); i++) {
			if (i < hLength && hBars[i] - hBars[i - 1] == 1) {
				tempH++;
			} else if (i < hLength) {
				maxConsecutiveHBars = max(maxConsecutiveHBars, tempH);
				tempH = 1;
			}
			if (i < vLength && vBars[i] - vBars[i - 1] == 1) {
				tempV++;
			} else if (i < vLength) {
				maxConsecutiveVBars = max(maxConsecutiveVBars, tempV);
				tempV = 1;
			}
		}

		maxConsecutiveHBars = max(maxConsecutiveHBars, tempH);
		maxConsecutiveVBars = max(maxConsecutiveVBars, tempV);

		int squareLen = min(maxConsecutiveHBars, maxConsecutiveVBars) + 1;

		return squareLen * squareLen;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)