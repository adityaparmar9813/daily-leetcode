class Solution {
   public:
	inline int sumDigits(int n) {
		int ans = 0;

		while (n != 0) {
			ans += n % 10;
			n /= 10;
		}
		return ans;
	}

	int countLargestGroup(int n) {
		vector<int> mp(37, 0);

		for (int i = 1; i <= n; i++) {
			mp[sumDigits(i)]++;
		}

		int maxi = 0, count = 0;

		for (int i = 1; i < 37; i++) {
			if (mp[i] > maxi) {
				maxi = mp[i];
				count = 1;
			} else if (mp[i] == maxi) {
				count++;
			}
		}

		return count;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)