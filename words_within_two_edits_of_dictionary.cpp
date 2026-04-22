class Solution {
   public:
	struct Trie {
		Trie* child[26];
		bool end = false;

		Trie() {
			for (int i = 0; i < 26; i++) child[i] = NULL;
		}
	};

	Trie* root = new Trie();

	void insert(string& s) {
		Trie* node = root;

		for (char c : s) {
			int i = c - 'a';

			if (!node->child[i]) {
				node->child[i] = new Trie();
			}
			node = node->child[i];
		}
		node->end = true;
	}

	bool dfs(string& s, int idx, Trie* node, int edits) {
		if (edits > 2) {
			return false;
		}
		if (idx == s.size()) {
			return node->end;
		}

		for (int i = 0; i < 26; i++) {
			if (node->child[i]) {
				int newEdit = edits + (i != (s[idx] - 'a'));

				if (dfs(s, idx + 1, node->child[i], newEdit)) {
					return true;
				}
			}
		}
		return false;
	}

	vector<string> twoEditWords(vector<string>& queries,
	                            vector<string>& dictionary) {
		for (auto& w : dictionary) insert(w);

		vector<string> ans;

		for (auto& q : queries) {
			if (dfs(q, 0, root, 0)) {
				ans.push_back(q);
			}
		}

		return ans;
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)