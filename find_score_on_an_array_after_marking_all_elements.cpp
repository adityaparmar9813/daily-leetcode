class Solution {
  public:
	long long findScore(vector<int> &nums) {
		long long ans = 0;

		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			if (p1.first == p2.first) {
				return p1.second > p2.second;
			}
			return p1.first > p2.first;
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
			pq(cmp);
		set<int> marked;

		for (int i = 0; i < nums.size(); i++) {
			pq.push({nums[i], i});
		}

		while (!pq.empty()) {
			auto [num, index] = pq.top();
			pq.pop();

			if (marked.find(index) != marked.end()) {
				continue;
			}

			ans += num;

			marked.insert(index - 1);
			marked.insert(index);
			marked.insert(index + 1);
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)