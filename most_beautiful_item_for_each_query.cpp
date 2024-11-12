class Solution {
  public:
	int binarySearch(vector<vector<int>> &items, int query) {
		int l = 0, r = items.size() - 1;
		int ans = 0;

		while (l <= r) {
			int mid = l + (r - l) / 2;
			int price = items[mid][0], beauty = items[mid][1];

			if (price <= query) {
				ans = beauty;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return ans;
	}

	vector<int> maximumBeauty(vector<vector<int>> &items,
							  vector<int> &queries) {
		sort(items.begin(), items.end());

		vector<int> ans;
		int maxBeauty = 0;

		for (int i = 0; i < items.size(); i++) {
			maxBeauty = max(maxBeauty, items[i][1]);
			items[i][1] = maxBeauty;
		}

		for (int query : queries) {
			ans.push_back(binarySearch(items, query));
		}

		return ans;
	}
};

// Time Complexity: O(n * log(n) + m * log(n))
// Space Complexity: O(1)