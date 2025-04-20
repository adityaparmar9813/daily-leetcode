class Solution {
   public:
	int numRabbits(vector<int>& answers) {
		unordered_map<int, int> mp;
		int ans = 0;

		for (int answer : answers) {
			mp[answer]++;
		}

		for (const auto& [num, count] : mp) {
			cout << num << " " << count << endl;
			ans += ceil(count / double(num + 1)) * (num + 1);
		}

		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)