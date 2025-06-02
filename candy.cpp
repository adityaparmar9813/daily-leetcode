class Solution {
   public:
	int candy(vector<int>& ratings) {
		vector<int> prefix(ratings.size(), 0);
		prefix[0] = 1;
		int right = 1;

		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				prefix[i] = prefix[i - 1] + 1;
			} else {
				prefix[i] = 1;
			}
		}

		int sum = max(prefix[ratings.size() - 1], 1);

		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				right++;
			} else {
				right = 1;
			}
			sum += max(prefix[i], right);
		}
		return sum;
	}
};

// Time complexity: O(n)
// Space complexity: O(n)