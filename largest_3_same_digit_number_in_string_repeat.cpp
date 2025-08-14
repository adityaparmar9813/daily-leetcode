class Solution {
   public:
	string largestGoodInteger(string num) {
		int index = -1;

		for (int left = 0; left < num.size() - 2; left++) {
			if (num[left] != num[left + 1] || num[left] != num[left + 2]) {
				continue;
			}
			if (index == -1 || num[left] > num[index]) {
				index = left;
			}
		}

		return index == -1 ? "" : num.substr(index, 3);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)