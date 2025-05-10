class Solution {
   public:
	using ll = long long;
	pair<ll, ll> counter(vector<int>& nums) {
		pair<ll, ll> res = {0, 0};

		for (int num : nums) {
			if (num != 0) {
				res.first += num;
			} else {
				res.second++;
			}
		}

		return res;
	}
	long long minSum(vector<int>& nums1, vector<int>& nums2) {
		auto c1 = counter(nums1), c2 = counter(nums2);

		if (c1.second == 0 && c2.first + c2.second > c1.first) {
			return -1;
		}
		if (c2.second == 0 && c1.first + c1.second > c2.first) {
			return -1;
		}

		return max(c1.first + c1.second, c2.first + c2.second);
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)