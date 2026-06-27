class Solution {
   public:
	int maximumLength(vector<int>& nums) {
		unordered_map<long long, int> mp;

		for (int num : nums) {
			mp[num]++;
		}

		int ans = 0;
		const long long LIMIT = 1e18;

		for (const auto& [key, value] : mp) {
			if (key == 1) {
				ans = max(ans, value % 2 == 0 ? value - 1 : value);
				continue;
			}

			int currAns = 0;
			long long k = key;

			while (k <= LIMIT) {
				auto it = mp.find(k);

				if (it == mp.end()) {
					currAns--;
					break;
				}

				if (it->second == 1) {
					currAns++;
					break;
				}

				currAns += 2;

				if (k > LIMIT / k) {
					break;
				}

				k *= k;
			}

			ans = max(ans, currAns);
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)