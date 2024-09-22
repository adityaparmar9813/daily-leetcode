class Solution {
  private:
	int countSteps(long long curr, long long n) {
		long long steps = 0;
		long long first = curr, last = curr;

		while (first <= n) {
			steps += min(last, n) - first + 1;
			first *= 10;
			last = last * 10 + 9;
		}
		return steps;
	}

  public:
	int findKthNumber(int n, int k) {
		long long curr = 1;
		k--;

		while (k > 0) {
			int steps = countSteps(curr, n);

			if (steps <= k) {
				k -= steps;
				curr++;
			} else {
				curr *= 10;
				k--;
			}
		}
		return curr;
	}
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)