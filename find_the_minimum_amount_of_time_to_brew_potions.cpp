class Solution {
   public:
	static long long minTime(vector<int>& skill, vector<int>& mana) {
		const int n = skill.size(), m = mana.size();

		partial_sum(skill.begin(), skill.end(), skill.begin());
		const int skill0 = skill[0];
		long long start = 0;

		for (int j = 1; j < m; j++) {
			const long long curr = mana[j], prev = mana[j - 1];
			long long tMax = skill0 * prev;
			for (int i = 1; i < n; i++)
				tMax = max(tMax, skill[i] * prev - skill[i - 1] * curr);
			start += tMax;
		}
		return start + 1LL * skill.back() * mana.back();
	}
};

// Time Complexity : O(m * n)
// Space Complexity : O(m + n)