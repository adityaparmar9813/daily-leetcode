class Solution {
   public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> copy = arr;
		sort(copy.begin(), copy.end());
		unordered_map<int, int> mp;
		int n = arr.size(), currRank = 1;

		if (n > 0) {
			mp[copy[0]] = currRank;
		}

		for (int i = 1; i < n; i++) {
			if (copy[i] != copy[i - 1]) {
				currRank++;
			}
			mp[copy[i]] = currRank;
		}

		for (int i = 0; i < n; i++) {
			arr[i] = mp[arr[i]];
		}

		return arr;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)