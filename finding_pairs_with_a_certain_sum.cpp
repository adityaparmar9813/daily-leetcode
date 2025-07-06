class FindSumPairs {
   public:
	vector<int> nums1;
	vector<int> nums2;
	unordered_map<int, int> mp;

	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		this->nums1 = nums1;
		this->nums2 = nums2;

		for (int num : nums2) {
			mp[num]++;
		}
	}

	void add(int index, int val) {
		int curr = nums2[index];
		nums2[index] += val;
		mp[curr]--;
		mp[curr + val]++;
	}

	int count(int tot) {
		int ans = 0;

		for (int num : nums1) {
			int req = tot - num;

			if (mp.find(req) != mp.end()) {
				ans += mp[req];
			}
		}

		return ans;
	}
};

// Time Complexity : O(n + m)
// Space Complexity : O(m)