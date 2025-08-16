class Solution {
   public:
	int maximum69Number(int num) {
		int curr = 1, index = 0, copy = num;

		while (copy != 0) {
			if (copy % 10 == 6) {
				index = curr;
			}
			copy = copy / 10;
			curr++;
		}

		return index == 0 ? num : num + pow(10, index - 1) * 3;
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(log(n))