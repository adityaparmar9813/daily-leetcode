class Solution {
   public:
	int st[100000], top = -1;

	int lcm(int x, int y) { return x / gcd(x, y) * y; }

	vector<int> replaceNonCoprimes(vector<int>& nums) {
		top = -1;

		for (int x : nums) {
			int cur = x;

			while (top != -1) {
				int g = gcd(st[top], cur);
				if (g == 1) break;
				cur = lcm(st[top], cur);
				top--;
			}
			st[++top] = cur;
		}

		return vector<int>(st, st + top + 1);
	}
};

// Time Complexity: O(n * log(max(nums)))
// Space Complexity: O(n)