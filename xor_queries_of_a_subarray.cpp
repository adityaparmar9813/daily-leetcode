class Solution {
  public:
	vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
		int n = arr.size();
		int m = queries.size();

		for (int i = 1; i < n; ++i) {
			arr[i] ^= arr[i - 1];
		}

		vector<int> ans;

		for (vector<int> query : queries) {
			if (query[0] == 0) {
				ans.push_back(arr[query[1]]);
			} else {
				ans.push_back(arr[query[1]] ^ arr[query[0] - 1]);
			}
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(1)