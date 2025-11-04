class Solution {
   public:
	vector<int> findXSum(vector<int>& nums, int k, int x) {
		int n = nums.size();
		vector<int> res;

		for (int i = 0; i + k <= n; i++) {
			unordered_map<int, int> count;

			for (int j = i; j < i + k; j++) {
				count[nums[j]]++;
			}

			vector<pair<int, int>> elements(count.begin(), count.end());

			sort(elements.begin(), elements.end(), [](auto& a, auto& b) {
				if (a.second == b.second) {
					return a.first > b.first;
				}
				return a.second > b.second;
			});

			int sum = 0, c = 0;

			for (auto& it : elements) {
				if (c == x) {
					break;
				}
				c++;
				sum += (it.first * it.second);
			}
			res.push_back(sum);
		}
		return res;
	}
};

// Time Complexity : O(n * k * log(k))
// Space Complexity : O(k)