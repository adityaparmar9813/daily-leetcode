class Solution {
   public:
	string lexGreaterPermutation(string s, string target) {
		int n = s.size();
		vector<int> total(26, 0);
		for (char c : s) {
			total[c - 'a']++;
		}

		vector<int> used(26, 0);
		int i = 0;

		while (i < n) {
			int c = target[i] - 'a';

			if (used[c] == total[c]) {
				break;
			}

			used[c]++;
			i++;
		}

		while (i >= 0) {
			if (i < n) {
				int current = target[i] - 'a';

				for (int next = current + 1; next < 26; next++) {
					if (used[next] == total[next]) {
						continue;
					}

					string answer = target.substr(0, i);
					answer += char('a' + next);

					for (int c = 0; c < 26; c++) {
						int remaining = total[c] - used[c];

						if (c == next) {
							remaining--;
						}

						answer += string(remaining, char('a' + c));
					}

					return answer;
				}
			}

			if (i > 0) {
				used[target[i - 1] - 'a']--;
			}

			i--;
		}

		return "";
	}
};

// Time Complexity: O(n)
// Space Complexity: O(1)