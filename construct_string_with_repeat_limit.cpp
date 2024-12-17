class Solution {
  public:
	string repeatLimitedString(string s, int k) {
		priority_queue<pair<char, int>> pq;
		vector<int> freq(26, 0);
		string result;

		for (char ch : s) {
			freq[ch - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (freq[i] > 0)
				pq.push({'a' + i, freq[i]});
		}

		while (!pq.empty()) {
			auto [ch, count] = pq.top();
			pq.pop();
			int used = min(k, count);
			result.append(used, ch);
			count -= used;

			if (count > 0) {
				if (pq.empty())
					break;
				auto [nextCh, nextCount] = pq.top();
				pq.pop();
				result += nextCh;
				nextCount--;

				if (nextCount > 0) {
					pq.push({nextCh, nextCount});
				}

				pq.push({ch, count});
			}
		}

		return result;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)