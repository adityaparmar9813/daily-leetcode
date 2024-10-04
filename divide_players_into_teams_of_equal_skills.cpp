class Solution {
  public:
	long long dividePlayers(std::vector<int> &skill) {
		sort(skill.begin(), skill.end());
		int l = 0, r = skill.size() - 1;

		int score = skill[l] + skill[r];
		long long ans = 0;

		while (l < r) {
			if (score != skill[l] + skill[r]) {
				return -1;
			}
			ans += (long long)skill[l++] * skill[r--];
		}

		return ans;
	}
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)