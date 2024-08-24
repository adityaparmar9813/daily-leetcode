class Solution {
  public:
	long long getPallindrome(string s) {
		long long n = s.size();
		long long l = (n - 1) / 2, r = (n) / 2;

		while (l >= 0) {
			s[r++] = s[l--];
		}

		return stoll(s);
	}

	long long binarySearchLeft(long long n) {
		long long l = n / 2, r = n;

		long long res = LLONG_MIN;
		while (l <= r) {
			long long mid = l + (r - l) / 2;

			long long palin = getPallindrome(to_string(mid));

			if (palin >= n)
				r = mid - 1;

			else {
				l = mid + 1;
				res = max(palin, res);
			}
		}
		return res;
	}

	long long binarySearchRight(long long n) {
		long long l = n, r = 1e18 - 1;
		long long res = LLONG_MAX;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			long long palin = getPallindrome(to_string(mid));
			if (palin <= n) {
				l = mid + 1;
			} else {
				r = mid - 1;
				res = min(res, palin);
			}
		}
		return res;
	}

	string nearestPalindromic(string n) {
		long long num = stoll(n);
		long long left = binarySearchLeft(num);
		long long right = binarySearchRight(num);

		return num - left > right - num ? to_string(right) : to_string(left);
	}
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)