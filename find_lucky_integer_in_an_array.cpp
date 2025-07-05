class Solution {
   public:
	int findLucky(vector<int>& arr) {
		vector<int> count(501, 0);

		for (const int& num : arr) {
			count[num]++;
		}

		for (int i = 500; i > 0; i--) {
			if (count[i] == i) {
				return i;
			}
		}

		return -1;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)