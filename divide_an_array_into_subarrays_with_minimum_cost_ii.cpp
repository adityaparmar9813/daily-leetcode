#define ll long long
class Solution {
   public:
	long long minimumCost(vector<int>& nums, int k, int dist) {
		ll n = nums.size();
		ll ans = LLONG_MAX;
		ll sum = 0;

		multiset<int> s, b;

		auto helper = [&]() {
			while (s.size() > k - 1) {
				auto it = prev(s.end());
				sum -= *it;
				b.insert(*it);
				s.erase(it);
			}
			while (s.size() < k - 1 && !b.empty()) {
				auto it = b.begin();
				sum += *it;
				s.insert(*it);
				b.erase(it);
			}
		};

		auto add = [&](ll x) {
			if (s.empty() || x <= *prev(s.end())) {
				s.insert(x);
				sum += x;
			} else
				b.insert(x);
			helper();
		};

		auto remove = [&](ll x) {
			if (s.find(x) != s.end()) {
				s.erase(s.find(x));
				sum -= x;
			} else
				b.erase(b.find(x));
			helper();
		};

		ll l = 1, r = 1 + dist;

		for (int i = l; i <= r; i++) add(nums[i]);

		ans = sum;

		while (r + 1 < n) {
			remove(nums[l]);
			l++;
			r++;
			add(nums[r]);
			ans = min(ans, sum);
		}

		return ans + nums[0];
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)