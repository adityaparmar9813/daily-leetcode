class Solution {
   public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int left = 0, sum = 0, maxFruits = 0;
		for (int right = 0; right < fruits.size(); ++right) {
			sum += fruits[right][1];
			while (left <= right &&
			       minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
				sum -= fruits[left][1];
				left++;
			}
			maxFruits = max(maxFruits, sum);
		}
		return maxFruits;
	}

	int minSteps(int left, int right, int start) {
		return min(abs(start - left) + (right - left),
		           abs(start - right) + (right - left));
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)