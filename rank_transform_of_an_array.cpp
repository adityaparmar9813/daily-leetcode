class Solution {
  public:
	vector<int> arrayRankTransform(vector<int> &arr) {
		vector<int> copy = arr;
		sort(copy.begin(), copy.end());

		unordered_map<int, int> mp;
		int rank = 1;

		for (int num : copy) {
			if (mp.find(num) == mp.end()) {
				mp[num] = rank++;
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			arr[i] = mp[arr[i]];
		}
		return arr;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)