class Solution {
   public:
	int parent[26];
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		for (int i = 0; i < 26; ++i) {
			parent[i] = i;
		}

		for (int i = 0; i < s1.length(); i++) {
			unionSets(s1[i] - 'a', s2[i] - 'a');
		}

		string result = "";
		for (char ch : baseStr) {
			result += (char)(find(ch - 'a') + 'a');
		}

		return result;
	}

   private:
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}

		return parent[x];
	}

	void unionSets(int x, int y) {
		int px = find(x), py = find(y);
		if (px == py) {
			return;
		}

		if (px < py) {
			parent[py] = px;
		} else {
			parent[px] = py;
		}
	}
};

// Time Complexity: O(n + m)
// Space Complexity: O(1)