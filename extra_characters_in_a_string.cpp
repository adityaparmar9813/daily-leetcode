class TrieNode {
  public:
	vector<TrieNode *> children;
	bool isTerminal;

	TrieNode() {
		children.resize(26, nullptr);
		isTerminal = false;
	}
};

class Trie {
  public:
	TrieNode *root;

	Trie() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode *curr = root;
		for (char ch : word) {
			int index = ch - 'a';
			if (!curr->children[index]) {
				curr->children[index] = new TrieNode();
			}
			curr = curr->children[index];
		}
		curr->isTerminal = true;
	}

	void insert(vector<string> &dictionary) {
		for (const string &word : dictionary) {
			insert(word);
		}
	}
};

class Solution {
  public:
	int minExtraChar(string s, vector<string> &dictionary) {
		Trie trie;
		trie.insert(dictionary);

		int n = s.size();
		vector<int> dp(n + 1, 0);

		for (int i = n - 1; i >= 0; i--) {
			dp[i] = dp[i + 1] + 1;
			TrieNode *node = trie.root;

			for (int j = i; j < n; j++) {
				if (!node->children[s[j] - 'a']) {
					break;
				}
				node = node->children[s[j] - 'a'];

				if (node->isTerminal) {
					dp[i] = min(dp[i], dp[j + 1]);
				}
			}
		}

		return dp[0];
	}
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)